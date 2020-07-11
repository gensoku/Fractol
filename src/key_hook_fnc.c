/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_fnc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:05:01 by tsedigi           #+#    #+#             */
/*   Updated: 2016/05/11 10:05:03 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				mouse_hook3(int x, int y, t_thrarg *threads)
{
	t_env		*e;

	e = threads[0].e;
	refresh_color_cl(e);
	if (!e->lock && !e->drag && e->is_julia_lock)
	{
		e->jr += (float)(x - e->mouse_x) * JSTEP;
		e->ji += (float)(y - e->mouse_y) * JSTEP;
		refresh_img(threads, e);
		e->mouse_y = y;
		e->mouse_x = x;
	}
	else if (e->lock && e->drag)
	{
		if (e->set == 0)
			move_mandelbrot_julia(threads, x - e->mouse_x, y - e->mouse_y);
		else
		{
			e->jr += (float)(x - e->mouse_x) * JSTEP;
			e->ji += (float)(y - e->mouse_y) * JSTEP;
			refresh_img(threads, e);
		}
	}
	return (0);
}

static void		set_j_point(t_env *e)
{
	if (e->j_point == 0)
	{
		e->jr = 0.0;
		e->ji = 0.0;
	}
	else if (e->j_point == 1)
	{
		e->jr = -1.0;
		e->ji = 0.0;
	}
	else if (e->j_point == 2)
	{
		e->jr = -1.7548;
		e->ji = 0.0;
	}
	else if (e->j_point == 3)
	{
		e->jr = -1.310;
		e->ji = 0.0;
	}
	else if (e->j_point == 4)
	{
		e->jr = 0.28;
		e->ji = 0.53;
	}
}

void			key_p(t_thrarg *threads, t_env *e)
{
	if (e->type != JULIA)
		return ;
	if (e->j_point < MAX_J_POINT)
		e->j_point++;
	else
		e->j_point = 0;
	set_j_point(e);
	refresh_color_cl(e);
	if (e->mode == HARDCORE)
		core_mandelbrot_julia(threads);
	else
		gpu_mandelbrot(e);
}

int				mouse_hook_4(int button, t_thrarg *threads)
{
	t_env		*e;

	e = threads[0].e;
	(void)button;
	e->is_pressed = 0;
	return (0);
}

int				mouse_hook_2(int button, int x, int y, t_thrarg *threads)
{
	t_env		*e;

	e = threads[0].e;
	(void)threads;
	(void)y;
	(void)x;
	if (button == 1)
		e->drag = 0;
	return (0);
}
