/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_keycode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 08:27:17 by tsedigi           #+#    #+#             */
/*   Updated: 2016/05/17 08:27:22 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_f(t_thrarg *threads, t_env *e)
{
	if (e->type == JULIA && !e->lock)
	{
		if (e->is_julia_lock == 0)
			e->is_julia_lock = 1;
		else
			e->is_julia_lock = 0;
	}
	if (e->mode == HARDCORE)
		core_mandelbrot_julia(threads);
	else
		gpu_mandelbrot(e);
	print_to_screen(e);
}
