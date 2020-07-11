/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:05:33 by tsedigi           #+#    #+#             */
/*   Updated: 2016/05/11 10:05:35 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			new_ext_2(t_env *e)
{
	e->x_centred = e->min_x + (e->max_x - e->min_x) /
		WIDTH * (e->x_centred);
	e->y_centred = e->min_y + (e->max_y - e->min_y) /
		HEIGHT * (HEIGHT - e->y_centred);
	e->diff_i = (e->max_x - e->min_x) * 2;
	e->min_x = e->x_centred - e->diff_i / 2;
	e->max_x = e->x_centred + e->diff_i / 2;
	e->min_y = e->y_centred - e->diff_i / 2;
	e->max_y = e->y_centred + e->diff_i / 2;
}

static void			mouse_hook_2_n(int x, int y, t_thrarg *threads, t_env *e)
{
	if (WIDTH > x && x > 0 && HEIGHT > y && y > 0 && e->lock == 0)
	{
		e->x_centred = x;
		e->y_centred = y;
		e->x = 0;
		e->y = 0;
		new_ext_2(e);
		if (e->mode == HARDCORE)
			core_mandelbrot_julia(threads);
		else
			gpu_mandelbrot(e);
	}
	else if (WIDTH > x && x > 0 && HEIGHT > y && y > 0)
	{
		e->drag = 1;
		e->mouse_x = x;
		e->mouse_y = y;
	}
}

static void			mouse_hook_1_n(int x, int y, t_thrarg *threads, t_env *e)
{
	if (WIDTH > x && x > 0 && HEIGHT > y && y > 0 && e->lock == 0)
	{
		e->x_centred = x;
		e->y_centred = y;
		e->x = 0;
		e->y = 0;
		new_ext(e);
		e->real_zoom *= (int)(1.0 / e->zoom);
		if (e->mode == HARDCORE)
			core_mandelbrot_julia(threads);
		else
			gpu_mandelbrot(e);
	}
	else if (WIDTH > x && x > 0 && HEIGHT > y && y > 0)
	{
		e->drag = 1;
		e->mouse_x = x;
		e->mouse_y = y;
	}
}

void				key_return(t_thrarg *threads, t_env *e)
{
	set_env_(e);
	core_mandelbrot_julia(threads);
}

int					mouse_hook(int button, int x, int y, t_thrarg *threads)
{
	t_env			*e;

	e = threads[0].e;
	if (e->type != JULIA)
		e->set = 0;
	if ((button == 1 || button == 6) && !e->is_julia_lock)
		mouse_hook_1_n(x, y, threads, e);
	else if ((button == 2 || button == 7) && !e->is_julia_lock)
		mouse_hook_2_n(x, y, threads, e);
	return (0);
}
