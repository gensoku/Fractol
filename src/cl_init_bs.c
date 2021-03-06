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

char				**get_source_from_id_1(int id)
{
	static char		**programs = NULL;
	int				fd;
	int				count;

	if (programs == NULL)
	{
		programs = malloc(sizeof(char *) * NB_PROGRAMS);
		programs[ID_MANDE] = ft_memalloc(SZ_BURNS + 1);
		fd = open(NM_BURNS, O_RDONLY);
		if ((count = read(fd, programs[ID_MANDE], SZ_BURNS)) != SZ_BURNS)
			ft_putstr_fd("Warning : not the right size \n", 2);
		close(fd);
	}
	return (programs + id);
}

static void			opencl_init_1(t_env *e, int err)
{
	e->bs_k_init = clCreateKernel(e->bs_source, "init_vals", &err);
	if (err)
		ft_putstr_fd("Kernel creation failed somehow.", 2);
	e->bs_k_calc = clCreateKernel(e->bs_source, "burning_ship", &err);
	if (err)
		ft_putstr_fd("Kernel creation failed somehow.", 2);
	e->bs_cl_vals = clCreateBuffer(e->bs_context, CL_MEM_READ_WRITE,
			sizeof(t_val) * WIDTH * HEIGHT, NULL, NULL);
	e->bs_cl_buff = clCreateBuffer(e->bs_context, CL_MEM_READ_WRITE,
			sizeof(int) * WIDTH * HEIGHT, NULL, NULL);
	e->bs_cl_data = clCreateBuffer(e->bs_context, CL_MEM_READ_WRITE,
			sizeof(t_data), NULL, NULL);
	e->bs_cl_colors = clCreateBuffer(e->bs_context, CL_MEM_READ_WRITE,
			sizeof(int) * e->n_colors, NULL, NULL);
	clEnqueueWriteBuffer(e->bs_queue, e->bs_cl_colors, CL_TRUE, 0,
			sizeof(int) * e->n_colors, e->color, 0, NULL, NULL);
	clFinish(e->bs_queue);
}

void				opencl_init_bs(t_env *e)
{
	cl_device_id	device_id;
	int				err;
	cl_platform_id	platform;

	clGetPlatformIDs(1, &platform, NULL);
	clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device_id, NULL);
	e->bs_context = clCreateContext(0, 1, &device_id, NULL, NULL, &err);
	if (err)
	{
		ft_putstr_fd("context error : ", 2);
		ft_putnbr_fd(err, 2);
	}
	e->bs_queue = clCreateCommandQueue(e->bs_context, device_id, 0, NULL);
	e->bs_source = clCreateProgramWithSource(e->bs_context, 1,
			(const char **)get_source_from_id_1(0), NULL, NULL);
	clBuildProgram(e->bs_source, 0, NULL, NULL, NULL, NULL);
	opencl_init_1(e, err);
}

void				opencl_set_kernels_bs(t_env *e)
{
	clSetKernelArg(e->bs_k_init, 0, sizeof(cl_mem), &e->bs_cl_data);
	clSetKernelArg(e->bs_k_init, 1, sizeof(cl_mem), &e->bs_cl_vals);
	clSetKernelArg(e->bs_k_calc, 0, sizeof(cl_mem), &e->bs_cl_vals);
	clSetKernelArg(e->bs_k_calc, 1, sizeof(cl_mem), &e->bs_cl_buff);
	clSetKernelArg(e->bs_k_calc, 2, sizeof(int), &e->max_iter);
	clSetKernelArg(e->bs_k_calc, 3, sizeof(cl_mem), &e->bs_cl_colors);
	clSetKernelArg(e->bs_k_calc, 4, sizeof(int), &e->n_colors);
	e->bs_i_gl[0] = WIDTH;
	e->bs_i_gl[1] = HEIGHT;
	e->bs_c_gl[0] = WIDTH;
	e->bs_c_gl[1] = HEIGHT;
	e->bs_local[0] = 16;
	e->bs_local[1] = 16;
}
