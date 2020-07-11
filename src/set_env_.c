/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:05:49 by tsedigi           #+#    #+#             */
/*   Updated: 2016/05/11 10:05:51 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		set_env_2(t_env *e)
{
	e->save_x = 0;
	e->save_y = 0;
	e->scale = 2;
	e->is_pressed = 0;
	e->type = JULIA;
	e->jr = -0.7589;
	e->ji = 0.0753;
	e->lock = 0;
	e->drag = 0;
	e->set = 0;
	e->n_colors = NUM_COLORS_FULL;
	e->real_zoom = 1;
	e->cam.x = 0;
	e->cam.y = 0;
	e->cam.z = -10;
	e->rot.x = 0;
	e->rot.y = 0;
	e->color_type = FULL_COL;
	e->type_low = 0;
	e->j_point = 0;
	set_color(e);
	set_color_bis(e);
}

void			set_env_(t_env *e)
{
	e->endian = 0;
	e->bpp = 0;
	e->size_max = 0;
	e->tab[0] = 0;
	e->tab[1] = 0;
	e->tab[2] = 0;
	e->flag_on = 1;
	e->x_cur = 0;
	e->y_cur = 0;
	e->max_iter = 250;
	e->zoom = 0.5;
	e->x_centred = 0;
	e->y_centred = 0;
	e->min_x = -2.0;
	e->min_y = -2.0;
	e->max_x = 2.0;
	e->max_y = 2.0;
	e->scale = 1;
	e->diff_i = 0;
	e->scale_fact = 2.0;
	e->move_x = 1 / WIDTH;
	e->move_y = 1 / HEIGHT;
	e->is_julia_lock = 0;
	e->mode = HARDCORE;
	set_env_2(e);
}
