/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:03:37 by tsedigi           #+#    #+#             */
/*   Updated: 2016/05/11 10:03:39 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char				**get_source_from_id(int id)
{
	static char		**programs = NULL;
	int				fd;
	int				count;

	if (programs == NULL)
	{
		programs = malloc(sizeof(char *) * NB_PROGRAMS);
		programs[ID_MANDE] = ft_memalloc(SZ_MANDE + 1);
		fd = open(NM_MANDE, O_RDONLY);
		if ((count = read(fd, programs[ID_MANDE], SZ_MANDE)) != SZ_MANDE)
			ft_putstr_fd("Warning : not the right size \n", 2);
		close(fd);
	}
	return (programs + id);
}

static void			opencl_init_1(t_env *e, int err)
{
	e->k_init = clCreateKernel(e->source, "init_vals", &err);
	if (err)
		ft_putstr_fd("Kernel creation failed somehow.", 2);
	e->k_calc = clCreateKernel(e->source, "mandelbrot_julia", &err);
	if (err)
		ft_putstr_fd("Kernel creation failed somehow.", 2);
	e->cl_vals = clCreateBuffer(e->context, CL_MEM_READ_WRITE,
			sizeof(t_val) * WIDTH * HEIGHT, NULL, NULL);
	e->cl_buff = clCreateBuffer(e->context, CL_MEM_READ_WRITE,
			sizeof(int) * WIDTH * HEIGHT, NULL, NULL);
	e->cl_data = clCreateBuffer(e->context, CL_MEM_READ_WRITE,
			sizeof(t_data), NULL, NULL);
	e->cl_colors = clCreateBuffer(e->context, CL_MEM_READ_WRITE,
			sizeof(int) * e->n_colors, NULL, NULL);
	clEnqueueWriteBuffer(e->queue, e->cl_colors, CL_TRUE, 0,
			sizeof(int) * e->n_colors, e->color, 0, NULL, NULL);
	clFinish(e->queue);
}

void				opencl_init(t_env *e)
{
	cl_device_id	device_id;
	int				err;
	cl_platform_id	platform;

	clGetPlatformIDs(1, &platform, NULL);
	clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device_id, NULL);
	e->context = clCreateContext(0, 1, &device_id, NULL, NULL, &err);
	if (err)
	{
		ft_putstr_fd("context error : ", 2);
		ft_putnbr_fd(err, 2);
	}
	e->queue = clCreateCommandQueue(e->context, device_id, 0, NULL);
	e->source = clCreateProgramWithSource(e->context, 1,
			(const char **)get_source_from_id(0), NULL, NULL);
	clBuildProgram(e->source, 0, NULL, NULL, NULL, NULL);
	opencl_init_1(e, err);
}

void				opencl_set_kernels(t_env *e)
{
	clSetKernelArg(e->k_init, 0, sizeof(cl_mem), &e->cl_data);
	clSetKernelArg(e->k_init, 1, sizeof(cl_mem), &e->cl_vals);
	clSetKernelArg(e->k_calc, 0, sizeof(cl_mem), &e->cl_vals);
	clSetKernelArg(e->k_calc, 1, sizeof(cl_mem), &e->cl_buff);
	clSetKernelArg(e->k_calc, 2, sizeof(int), &e->max_iter);
	clSetKernelArg(e->k_calc, 3, sizeof(cl_mem), &e->cl_colors);
	clSetKernelArg(e->k_calc, 4, sizeof(int), &e->n_colors);
	e->i_gl[0] = WIDTH;
	e->i_gl[1] = HEIGHT;
	e->c_gl[0] = WIDTH;
	e->c_gl[1] = HEIGHT;
	e->local[0] = 16;
	e->local[1] = 16;
}
