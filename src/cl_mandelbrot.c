/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:13:34 by tsedigi           #+#    #+#             */
/*   Updated: 2016/05/11 10:13:35 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		gpu_free_mandel(t_env *e)
{
	clReleaseMemObject(e->cl_buff);
	clReleaseMemObject(e->cl_vals);
	clReleaseProgram(e->source);
	clReleaseKernel(e->k_init);
	clReleaseKernel(e->k_calc);
	clReleaseCommandQueue(e->queue);
	clReleaseContext(e->context);
	gpu_free_bs(e);
}

void		gpu_free_bs(t_env *e)
{
	clReleaseMemObject(e->bs_cl_buff);
	clReleaseMemObject(e->bs_cl_vals);
	clReleaseProgram(e->bs_source);
	clReleaseKernel(e->bs_k_init);
	clReleaseKernel(e->bs_k_calc);
	clReleaseCommandQueue(e->bs_queue);
	clReleaseContext(e->bs_context);
}

void		gpu_burning_ship(t_env *e)
{
	t_data	data;

	data = new_data(e);
	clSetKernelArg(e->bs_k_calc, 2, sizeof(int), &e->max_iter);
	clEnqueueWriteBuffer(e->bs_queue, e->bs_cl_data, CL_TRUE, 0,
		sizeof(t_data), &data, 0, NULL, NULL);
	clEnqueueNDRangeKernel(e->bs_queue, e->bs_k_init, 2, NULL,
		e->bs_i_gl, e->bs_local, 0, NULL, NULL);
	clEnqueueNDRangeKernel(e->bs_queue, e->bs_k_calc, 2, NULL,
		e->bs_c_gl, e->bs_local, 0, NULL, NULL);
	clFinish(e->bs_queue);
	clEnqueueReadBuffer(e->bs_queue, e->bs_cl_buff, CL_TRUE, 0,
		sizeof(int) * WIDTH * HEIGHT, e->data, 0, NULL, NULL);
	clFinish(e->bs_queue);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	print_to_screen(e);
}

void		gpu_mandelbrot(t_env *e)
{
	t_data	data;

	if (e->type == BURNING)
	{
		gpu_burning_ship(e);
		return ;
	}
	data = new_data(e);
	clSetKernelArg(e->k_calc, 2, sizeof(int), &e->max_iter);
	clEnqueueWriteBuffer(e->queue, e->cl_data, CL_TRUE, 0,
		sizeof(t_data), &data, 0, NULL, NULL);
	clEnqueueNDRangeKernel(e->queue, e->k_init, 2, NULL,
		e->i_gl, e->local, 0, NULL, NULL);
	clEnqueueNDRangeKernel(e->queue, e->k_calc, 2, NULL,
		e->c_gl, e->local, 0, NULL, NULL);
	clFinish(e->queue);
	clEnqueueReadBuffer(e->queue, e->cl_buff, CL_TRUE, 0,
		sizeof(int) * WIDTH * HEIGHT, e->data, 0, NULL, NULL);
	clFinish(e->queue);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	print_to_screen(e);
}
