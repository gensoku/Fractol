/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_color_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:06:41 by tsedigi           #+#    #+#             */
/*   Updated: 2016/05/11 10:06:42 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set_color16(t_env *e)
{
	e->color[355] = 0x8b;
	e->color[356] = 0x8b8b;
	e->color[357] = 0x8b008b;
	e->color[358] = 0x8b0000;
	e->color[359] = 0x90ee90;
}

void		set_color_bis_4(t_env *e)
{
	e->color_bis[0] = 0xE04902;
	e->color_bis[1] = 0x2A0001;
	e->color_bis[2] = 0x330000;
	e->color_bis[3] = 0x3C0000;
	e->color_bis[4] = 0x440001;
	e->color_bis[5] = 0x4C0002;
	e->color_bis[6] = 0x5D0000;
	e->color_bis[7] = 0xCE4612;
	e->color_bis[8] = 0xED9D41;
}
