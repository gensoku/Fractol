/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_fnc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:04:17 by tsedigi           #+#    #+#             */
/*   Updated: 2016/05/11 10:04:19 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_thrarg *threads)
{
	t_env	*e;

	e = threads[0].e;
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	print_to_screen(e);
	return (0);
}
