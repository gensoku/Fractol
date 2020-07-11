/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_cl_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:06:49 by tsedigi           #+#    #+#             */
/*   Updated: 2016/05/11 10:06:51 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data			new_data(t_env *e)
{
	t_data		data;

	data.min_x = e->min_x;
	data.max_x = e->max_x;
	data.min_y = e->min_y;
	data.max_y = e->max_y;
	data.jr = e->jr;
	data.ji = e->ji;
	data.width = WIDTH;
	data.height = HEIGHT;
	data.type = e->type;
	return (data);
}

void			refresh_color_cl(t_env *e)
{
	if (e->type == BURNING)
	{
		clEnqueueWriteBuffer(e->bs_queue, e->bs_cl_colors, CL_TRUE, 0,
			sizeof(int) * e->n_colors, e->color_type ?
			e->color_bis : e->color, 0, NULL, NULL);
		clSetKernelArg(e->bs_k_calc, 3, sizeof(cl_mem), &e->bs_cl_colors);
		clSetKernelArg(e->bs_k_calc, 4, sizeof(int), &e->n_colors);
	}
	else
	{
		clEnqueueWriteBuffer(e->queue, e->cl_colors, CL_TRUE, 0,
			sizeof(int) * e->n_colors, e->color_type ?
			e->color_bis : e->color, 0, NULL, NULL);
		clSetKernelArg(e->k_calc, 3, sizeof(cl_mem), &e->cl_colors);
		clSetKernelArg(e->k_calc, 4, sizeof(int), &e->n_colors);
	}
}

t_lims			new_lims(int ymin, int xmin, int ymax, int xmax)
{
	t_lims		lim;

	lim.ymin = ymin;
	lim.xmin = xmin;
	lim.ymax = ymax;
	lim.xmax = xmax;
	return (lim);
}

void			refresh_img(t_thrarg *threads, t_env *e)
{
	if (e->mode == HARDCORE)
		core_mandelbrot_julia(threads);
	else
		gpu_mandelbrot(e);
}

void			init_mandel_julia(t_mandel *curent, int xmin, int ymin)
{
	curent->rc = 0;
	curent->ic = 0;
	curent->rz = 0;
	curent->iz = 0;
	curent->r = 0;
	curent->i = 0;
	curent->a = 0;
	curent->nb = 0;
	curent->x = xmin;
	curent->y = ymin;
}
