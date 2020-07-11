/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:03:51 by tsedigi           #+#    #+#             */
/*   Updated: 2016/05/11 10:03:54 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(t_env *e, int color)
{
	if (color == e->max_iter)
		return (0);
	if (e->color_type == FULL_COL)
		return (e->color[color % e->n_colors]);
	else
		return (e->color_bis[color % e->n_colors]);
}
