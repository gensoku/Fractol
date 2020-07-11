/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:05:11 by tsedigi           #+#    #+#             */
/*   Updated: 2016/05/11 10:05:12 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				calc_iter_burning(t_env *e, t_mandel *curent)
{
	curent->ic = e->max_y - (e->max_y - e->min_y) / HEIGHT * curent->y;
	curent->rz = 0;
	curent->iz = 0;
	curent->a = 0;
	while (curent->rz * curent->rz + curent->iz * curent->iz <= 4.0
		&& curent->a < e->max_iter)
	{
		curent->r = curent->rz * curent->rz -
			curent->iz * curent->iz + curent->rc;
		curent->i = 2 * fabs(curent->rz) * fabs(curent->iz) + curent->ic;
		curent->rz = curent->r;
		curent->iz = curent->i;
		curent->a++;
	}
	((int *)e->data)[curent->x + curent->y * WIDTH] = get_color(e, curent->a);
}

void				*burning_ship(void *data)
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

void				*mandelbrot_julia(void *data)
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

void				core_mandelbrot_julia(t_thrarg *args)
{
	pthread_t		threads[NUM_THREADS];
	int				i;
	t_env			*e;

	e = args[0].e;
	init_thr_data(args, e);
	i = -1;
	while (++i < NUM_THREADS)
	{
		if (e->type == BURNING)
			pthread_create(threads + i, NULL, &burning_ship, args + i);
		else
			pthread_create(threads + i, NULL, &mandelbrot_julia, args + i);
	}
	i = -1;
	while (++i < NUM_THREADS)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	print_to_screen(e);
}
