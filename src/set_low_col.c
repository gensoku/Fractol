/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_low_col.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:06:01 by tsedigi           #+#    #+#             */
/*   Updated: 2016/05/11 10:06:03 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		set_color_bis_3(t_env *e)
{
	e->color_bis[0] = 0xffffff;
	e->color_bis[1] = 0x727244;
	e->color_bis[2] = 0x626244;
	e->color_bis[3] = 0xa3a366;
	e->color_bis[4] = 0xe5e5aa;
	e->color_bis[5] = 0x636344;
	e->color_bis[6] = 0x535344;
	e->color_bis[7] = 0x858577;
	e->color_bis[8] = 0xb7b7aa;
}

static void		set_color_bis_2(t_env *e)
{
	e->color_bis[0] = 0xffffff;
	e->color_bis[1] = 0x336600;
	e->color_bis[2] = 0x336633;
	e->color_bis[3] = 0x336666;
	e->color_bis[4] = 0x336699;
	e->color_bis[5] = 0x339966;
	e->color_bis[6] = 0x006633;
	e->color_bis[7] = 0x009933;
	e->color_bis[8] = 0x003300;
}

static void		set_color_bis_1(t_env *e)
{
	e->color_bis[0] = 0xffffff;
	e->color_bis[1] = 0x330000;
	e->color_bis[2] = 0x330033;
	e->color_bis[3] = 0x330066;
	e->color_bis[4] = 0x330099;
	e->color_bis[5] = 0x3300CC;
	e->color_bis[6] = 0x3300FF;
	e->color_bis[7] = 0x0000CC;
	e->color_bis[8] = 0x000066;
}

void			set_color_bis(t_env *e)
{
	e->color_bis[0] = 0xffffff;
	e->color_bis[1] = 0x224477;
	e->color_bis[2] = 0x224466;
	e->color_bis[3] = 0x3366aa;
	e->color_bis[4] = 0x55aaee;
	e->color_bis[5] = 0x334466;
	e->color_bis[6] = 0x334455;
	e->color_bis[7] = 0x557788;
	e->color_bis[8] = 0x77aabb;
}

void			set_color_low(t_env *e)
{
	if (e->type_low == 0)
		set_color_bis(e);
	else if (e->type_low == 1)
		set_color_bis_1(e);
	else if (e->type_low == 2)
		set_color_bis_2(e);
	else if (e->type_low == 3)
		set_color_bis_3(e);
	else if (e->type_low == 4)
		set_color_bis_4(e);
}
