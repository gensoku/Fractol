/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu_mandel_core.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:04:00 by tsedigi           #+#    #+#             */
/*   Updated: 2016/05/11 10:04:02 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_iter_mandel(t_env *e, t_mandel *curent)
{
	curent->ic = (e->type == JULIA) ? e->ji : e->max_y -
		(e->max_y - e->min_y) / HEIGHT * curent->y;
	curent->rz = (e->type == JULIA) ? e->min_x +
		(e->max_x - e->min_x) / WIDTH * curent->x : 0;
	curent->iz = (e->type == JULIA) ? e->max_y -
		(e->max_y - e->min_y) / HEIGHT * curent->y : 0;
	curent->a = 0;
	while (curent->rz * curent->rz + curent->iz * curent->iz
		<= 4.0 && curent->a < e->max_iter)
	{
		curent->r = curent->rz;
		curent->i = curent->iz;
		curent->rz = curent->r * curent->r - curent->i * curent->i + curent->rc;
		curent->iz = 2 * curent->r * curent->i + curent->ic;
		curent->a++;
	}
	((int *)e->data)[curent->x + curent->y * WIDTH] = get_color(e, curent->a);
}
