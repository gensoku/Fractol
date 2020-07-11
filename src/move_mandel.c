/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mandel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 09:59:08 by tsedigi           #+#    #+#             */
/*   Updated: 2016/05/17 09:59:13 by tsedigi          ###   ########.fr       */
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

static void			n_(t_thrarg *ag, pthread_t t[NUM_THREADS], t_env *e, int x)
{
	long double		delta;
	int				i;

	delta = (e->max_x - e->min_x) * ((long double)(x) / WIDTH);
	e->min_x -= delta;
	e->max_x -= delta;
	if (x > 0)
		ft_memmove(e->data + 4 * x, e->data, HEIGHT * WIDTH * 4 - 4 * x);
	else
		ft_memmove(e->data, e->data - 4 * x, HEIGHT * WIDTH * 4 + 4 * x);
	i = -1;
	while (++i < NUM_THREADS)
		ag[i].lims = calc_lim(i, x, e->norm_y);
	i = -1;
	while (++i < NUM_THREADS)
	{
		if (e->type == BURNING)
			pthread_create(t + i, NULL, &burning_ship, ag + i);
		else
			pthread_create(t + i, NULL, &mandelbrot_julia, ag + i);
	}
	i = -1;
	while (++i < NUM_THREADS)
		pthread_join(t[i], NULL);
	e->mouse_x += x;
}

static void			norm_y_(t_env *e)
{
	long double		delta;
	int				x;
	int				y;

	x = e->norm_x;
	y = e->norm_y;
	delta = (e->max_y - e->min_y) * ((long double)y / HEIGHT);
	e->min_y += delta;
	e->max_y += delta;
	if (y > 0)
		ft_memmove(e->data + 4 * y * WIDTH, e->data, HEIGHT *
			WIDTH * 4 - 4 * WIDTH * y);
	else
		ft_memmove(e->data, e->data - 4 * y * WIDTH, HEIGHT *
			WIDTH * 4 + 4 * WIDTH * y);
}

void				move_mandelbrot_julia(t_thrarg *args, int x, int y)
{
	pthread_t		threads[NUM_THREADS];
	t_env			*e;

	e = args[0].e;
	e->norm_x = x;
	e->norm_y = y;
	if (x)
	{
		n_(args, threads, e, e->norm_x);
		x = 0;
		e->norm_x = 0;
	}
	if (y)
	{
		norm_y_(e);
		n_m_y(e, threads, args);
		e->norm_y = 0;
		y = 0;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	print_to_screen(e);
}
