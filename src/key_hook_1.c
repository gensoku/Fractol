/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:04:50 by tsedigi           #+#    #+#             */
/*   Updated: 2016/05/11 10:04:53 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	key_plus_num(t_thrarg *threads, t_env *e)
{
	e->max_iter += 50;
	refresh_color_cl(e);
	if (e->mode == HARDCORE)
		core_mandelbrot_julia(threads);
	else
		gpu_mandelbrot(e);
}

static void	key_3(t_thrarg *threads, t_env *e)
{
	e->type = BURNING;
	refresh_color_cl(e);
	if (e->mode == HARDCORE)
		core_mandelbrot_julia(threads);
	else
		gpu_mandelbrot(e);
}

static void	key_2(t_thrarg *threads, t_env *e)
{
	e->type = JULIA;
	refresh_color_cl(e);
	if (e->mode == HARDCORE)
		core_mandelbrot_julia(threads);
	else
		gpu_mandelbrot(e);
}

static void	key_1(t_thrarg *threads, t_env *e)
{
	e->type = MANDELBROT;
	refresh_color_cl(e);
	if (e->mode == HARDCORE)
		core_mandelbrot_julia(threads);
	else
		gpu_mandelbrot(e);
}

int			key_hook_2_n(int keycode, t_thrarg *threads)
{
	t_env	*e;

	e = threads[0].e;
	if (keycode == 18)
		key_1(threads, e);
	if (keycode == 19)
		key_2(threads, e);
	if (keycode == 20)
		key_3(threads, e);
	if (keycode == 69)
		key_plus_num(threads, e);
	if (keycode == 35)
		key_p(threads, e);
	if (keycode == 36)
		key_return(threads, e);
	if (keycode == 3)
		key_f(threads, e);
	return (0);
}
