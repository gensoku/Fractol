/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:03:23 by tsedigi           #+#    #+#             */
/*   Updated: 2016/05/11 10:08:07 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_thr_data(t_thrarg *threads, t_env *e)
{
	int			i;

	i = -1;
	while (++i < NUM_THREADS)
	{
		threads[i].e = e;
		threads[i].lims = new_lims(i * HEIGHT / NUM_THREADS, 0,
				(i + 1) * HEIGHT / NUM_THREADS, WIDTH);
	}
}

static void		hooks_(t_env *e, t_thrarg threads[NUM_THREADS])
{
	mlx_hook(e->win, MotionNotify, PointerMotionMask, mouse_hook3, threads);
	mlx_hook(e->win, ButtonPress, ButtonPressMask, mouse_hook, threads);
	mlx_hook(e->win, ButtonRelease, ButtonReleaseMask, mouse_hook_2, threads);
	mlx_hook(e->win, KeyRelease, KeyReleaseMask, mouse_hook_4, threads);
	mlx_hook(e->win, KeyPress, KeyPressMask, key_hook, threads);
	mlx_expose_hook(e->win, expose_hook, threads);
	mlx_loop(e->mlx);
}

static void		set_mlx(t_env *e)
{
	if ((e->mlx = mlx_init()) == NULL)
		display_err(-1, "mlx_init failed");
	if ((e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Fractol")) == NULL)
		display_err(-1, "mlx_new_window failed");
	if ((e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT)) == NULL)
		display_err(-1, "mlx_new_image failed");
	if ((e->data = mlx_get_data_addr(e->img, &e->bpp,
		&e->size_max, &e->endian)) == NULL)
		display_err(-1, "mlx_get_data_addr failed");
}

int				check_args(t_env *e, char *str)
{
	if (ft_strcmp(str, "julia") == 0)
	{
		e->type = JULIA;
		return (1);
	}
	else if (ft_strcmp(str, "mandelbrot") == 0)
	{
		e->type = MANDELBROT;
		return (1);
	}
	else if (ft_strcmp(str, "burning_ship") == 0)
	{
		e->type = BURNING;
		return (1);
	}
	return (-1);
}

int				main(int ac, char **av)
{
	t_env		*e;
	t_thrarg	threads[NUM_THREADS];

	if ((e = (t_env*)malloc(sizeof(t_env))) == NULL)
		display_err(-1, "malloc failed");
	if (ac != 2 || check_args(e, av[1]) == -1)
	{
		ft_putstr("command : ./fractol [julia/mandelbrot/burning_ship] \n");
		return (-1);
	}
	set_env_(e);
	set_mlx(e);
	init_thr_data(threads, e);
	opencl_init(e);
	opencl_init_bs(e);
	opencl_set_kernels(e);
	opencl_set_kernels_bs(e);
	if (check_args(e, av[1]) == -1)
		key_esc(e);
	if (e->mode == HARDCORE)
		core_mandelbrot_julia(threads);
	else
		gpu_mandelbrot(e);
	hooks_(e, threads);
	return (0);
}
