/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_mandel_julia.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:06:58 by tsedigi           #+#    #+#             */
/*   Updated: 2016/05/11 10:06:59 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			*burning_ship(void *data)
{
	t_mandel		curent;
	t_env			*e;
	t_lims			l;

	e = ((t_thrarg *)data)->e;
	l = ((t_thrarg *)data)->lims;
	init_mandel_julia(&curent, l.xmin, l.ymin);
	while (curent.x < l.xmax)
	{
		curent.rc = e->min_x + (e->max_x - e->min_x) / WIDTH * curent.x;
		while (curent.y < l.ymax)
		{
			calc_iter_burning(e, &curent);
			curent.y++;
		}
		curent.y = l.ymin;
		curent.x++;
	}
	pthread_exit(NULL);
}

static void			*mandelbrot_julia(void *data)
{
	t_mandel		curent;
	t_env			*e;
	t_lims			l;

	e = ((t_thrarg *)data)->e;
	l = ((t_thrarg *)data)->lims;
	init_mandel_julia(&curent, l.xmin, l.ymin);
	while (curent.x < l.xmax)
	{
		curent.rc = (e->type == JULIA) ? e->jr :
			e->min_x + (e->max_x - e->min_x) / WIDTH * curent.x;
		while (curent.y < l.ymax)
		{
			calc_iter_mandel(e, &curent);
			curent.y++;
		}
		curent.y = l.ymin;
		curent.x++;
	}
	pthread_exit(NULL);
}

void				n_m_y(t_env *e, pthread_t t[NUM_THREADS], t_thrarg *args)
{
	int				x;
	int				y;
	int				i;
	t_lims			lims[NUM_THREADS];

	x = e->norm_x;
	y = e->norm_y;
	i = -1;
	while (++i < NUM_THREADS)
		lims[i] = args[i].lims;
	i = -1;
	while (++i < NUM_THREADS)
		args[i].lims = calc_lim(i, x, y);
	i = -1;
	while (++i < NUM_THREADS)
	{
		if (e->type == BURNING)
			pthread_create(t + i, NULL, &burning_ship, args + i);
		else
			pthread_create(t + i, NULL, &mandelbrot_julia, args + i);
	}
	i = -1;
	while (++i < NUM_THREADS)
		pthread_join(t[i], NULL);
	e->mouse_y += y;
}

void				new_ext(t_env *e)
{
	e->x_centred = e->min_x + (e->max_x - e->min_x) /
		WIDTH * (e->x_centred);
	e->y_centred = e->min_y + (e->max_y - e->min_y) /
		HEIGHT * (HEIGHT - e->y_centred);
	e->diff_i = (e->max_x - e->min_x) * e->zoom;
	e->min_x = e->x_centred - e->diff_i / 2;
	e->max_x = e->x_centred + e->diff_i / 2;
	e->min_y = e->y_centred - e->diff_i / 2;
	e->max_y = e->y_centred + e->diff_i / 2;
}

t_lims				calc_lim(int i, int x, int y)
{
	t_lims			l;

	if (x == 0)
	{
		l.ymin = ((y < 0) ? HEIGHT + y : 0) +
			(int)(abs(y) * (float)i / NUM_THREADS);
		l.ymax = ((y < 0) ? HEIGHT + y : 0) +
			(int)(abs(y) * (float)(i + 1) / NUM_THREADS);
		l.xmin = 0;
		l.xmax = WIDTH;
	}
	else
	{
		l.ymin = (int)(HEIGHT * ((float)i / (float)NUM_THREADS));
		l.ymax = (int)(HEIGHT * ((float)(i + 1) / (float)NUM_THREADS));
		l.xmin = (x > 0) ? 0 : WIDTH + x;
		l.xmax = (x > 0) ? x : WIDTH;
	}
	return (l);
}
