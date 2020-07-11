/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:04:41 by tsedigi           #+#    #+#             */
/*   Updated: 2016/05/11 10:04:43 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		key_left_from_1_not_num(t_thrarg *threads, t_env *e)
{
	e->mode ^= 1;
	refresh_color_cl(e);
	if (e->mode == HARDCORE)
		core_mandelbrot_julia(threads);
	else
		gpu_mandelbrot(e);
}

static void		key_color_eq(t_thrarg *threads, t_env *e)
{
	if (!e->color_type)
		return ;
	if (e->type_low != MAX_LOW_SET)
		e->type_low++;
	else
		e->type_low = 0;
	set_color_low(e);
	refresh_color_cl(e);
	if (e->mode == HARDCORE)
		core_mandelbrot_julia(threads);
	else
		gpu_mandelbrot(e);
}

void			key_esc(t_env *e)
{
	gpu_free_mandel(e);
	mlx_destroy_image(e->mlx, e->img);
	mlx_destroy_window(e->mlx, e->win);
	ft_memdel((void **)&e->mlx);
	ft_memdel((void **)&e);
	exit(0);
}

static void		key_c(t_thrarg *threads, t_env *e)
{
	if (e->color_type == FULL_COL)
	{
		e->color_type = LOW_COL;
		e->n_colors = NUM_COLORS_LOW;
	}
	else
	{
		e->color_type = FULL_COL;
		e->n_colors = NUM_COLORS_FULL;
	}
	refresh_color_cl(e);
	if (e->mode == HARDCORE)
		core_mandelbrot_julia(threads);
	else
		gpu_mandelbrot(e);
}

int				key_hook(int keycode, t_thrarg *threads)
{
	t_env		*e;

	e = threads[0].e;
	if (keycode == 53)
		key_esc(e);
	if (keycode == 8)
		key_c(threads, e);
	if (keycode == 24)
		key_color_eq(threads, e);
	if (keycode == 50)
		key_left_from_1_not_num(threads, e);
	if (keycode == 49)
	{
		e->lock ^= 1;
		e->is_julia_lock = 0;
		refresh_img(threads, e);
	}
	if (keycode == 67 && e->lock && e->type == JULIA)
	{
		e->set ^= 1;
		refresh_img(threads, e);
	}
	key_hook_2_n(keycode, threads);
	return (0);
}
