/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:05:40 by tsedigi           #+#    #+#             */
/*   Updated: 2016/05/11 10:05:41 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	check_status(t_env *e)
{
	if (e->is_julia_lock && e->type == JULIA)
		mlx_string_put(e->mlx, e->win, 100, 75, 0x000000,
			"unlocked, move to modifiy julia ('f' to stop)");
	else if (e->lock && (e->type != JULIA || !e->set))
		mlx_string_put(e->mlx, e->win, 100, 75, 0x000000,
			"locked, drag to move ('space' to unlock)");
	else if (e->lock && e->type == JULIA && e->set)
		mlx_string_put(e->mlx, e->win, 100, 75, 0x000000,
			"locked, drag modifiy julia ('*' modifiy stop, 'space' unlock)");
	else if (!e->lock)
		mlx_string_put(e->mlx, e->win, 100, 75, 0x000000,
			"unlocked, clik to zoom ('space' to drag move)");
}

void			print_to_screen(t_env *e)
{
	int			i;
	double		ex;

	mlx_string_put(e->mlx, e->win, 10, 7, 0x000000, e->mode ? "CPU" : "GPU");
	if (e->type == BURNING)
		mlx_string_put(e->mlx, e->win, 10, 24, 0x000000, "Burning Ship set");
	else
		mlx_string_put(e->mlx, e->win, 10, 24, 0x000000, 1 - e->type ?
			"Mandelbrot set" : "Julia set");
	mlx_string_put(e->mlx, e->win, 10, 41, 0x000000, ft_itoa(e->max_iter));
	mlx_string_put(e->mlx, e->win, 50, 41, 0x000000, " iterations");
	ex = e->max_x - e->min_x;
	i = 0;
	while (ex < 1 && ++i)
		ex *= 10.0;
	mlx_string_put(e->mlx, e->win, 10, 58, 0x000000, "Precision : 10 ^ ");
	mlx_string_put(e->mlx, e->win, 170, 58, 0x000000, i ? "-" : "");
	mlx_string_put(e->mlx, e->win, 180, 58, 0x000000, ft_itoa(i));
	mlx_string_put(e->mlx, e->win, 10, 75, 0x000000, "status : ");
	check_status(e);
}
