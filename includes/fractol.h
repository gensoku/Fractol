/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:04:25 by tsedigi           #+#    #+#             */
/*   Updated: 2016/05/11 10:35:00 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "mlx_defines.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <pthread.h>
# include <OpenCL/opencl.h>

# define NUM_THREADS			8
# define NUM_COLORS_FULL		360
# define NUM_COLORS_LOW         9

# define MAX_J_POINT 			4

# define MAX_LOW_SET    4

# define GRAPHICS	0
# define HARDCORE	1

//# define WIDTH		2560
//# define HEIGHT		1440
# define WIDTH		1280
# define HEIGHT		720
# define SIZE		3686400

# define JSTEP			0.0001
# define MANDELBROT     0
# define JULIA			1
# define MANDELBULB		2
# define BURNING 		3

# define NB_PROGRAMS	1
# define ID_MANDE		0
# define SZ_MANDE		2528
# define SZ_BURNS       2024
# define NM_MANDE		"cl_mandelbrot.cl"
# define NM_BURNS       "cl_burning_s.cl"

# define FULL_COL   0
# define LOW_COL 	1

typedef struct			s_point
{
	double				x;
	double				y;
	double				z;
}						t_point;

typedef	struct			s_rot
{
	int					x;
	int					y;
}						t_rot;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data;
	int					mode;
	int					endian;
	int					bpp;
	int					lock;
	int					drag;
	int					set;
	int					size_max;
	int					tab[3];
	int					flag_on;
	int					x_cur;
	int					y_cur;
	int					is_pressed;
	int					type;
	int					n_colors;
	int					color_type;
	int					type_low;
	int					norm_x;
	int					norm_y;
	double				zoom;
	int					max_iter;
	double				x_centred;
	double				y_centred;
	int					mouse_x;
	int					mouse_y;
	int					color[360];
	int					color_bis[9];
	int					j_point;
	int					is_julia_lock;
	double				min_x;
	double				min_y;
	double				max_x;
	double				max_y;
	double				scale;
	double				move;
	double				diff_i;
	double				scale_fact;
	double				x;
	double				y;
	double				move_x;
	double				move_y;
	double				save_x;
	double				save_y;
	double				jr;
	double				ji;
	cl_context			context;
	cl_context			bs_context;
	cl_command_queue	queue;
	cl_command_queue	bs_queue;
	cl_program			source;
	cl_program			bs_source;
	cl_kernel			k_init;
	cl_kernel			bs_k_init;
	cl_kernel			k_calc;
	cl_kernel			bs_k_calc;
	cl_mem				cl_vals;
	cl_mem				bs_cl_vals;
	cl_mem				cl_buff;
	cl_mem				bs_cl_buff;
	cl_mem				cl_data;
	cl_mem				bs_cl_data;
	cl_mem				cl_colors;
	cl_mem				bs_cl_colors;
	size_t				i_gl[2];
	size_t				bs_i_gl[2];
	size_t				c_gl[2];
	size_t				bs_c_gl[2];
	size_t				local[2];
	size_t				bs_local[2];
	size_t				real_zoom;
	t_point				cam;
	t_rot				rot;
}						t_env;

typedef	struct			s_lims
{
	int					xmin;
	int					xmax;
	int					ymin;
	int					ymax;
}						t_lims;

typedef struct			s_thrarg
{
	t_lims				lims;
	t_env				*e;

}						t_thrarg;

typedef	struct			s_mandel
{
	double				rc;
	double				ic;
	double				rz;
	double				iz;
	double				r;
	double				i;
	int					a;
	int					nb;
	int					x;
	int					y;
}						t_mandel;

typedef	struct			s_data
{
	double				min_x;
	double				max_x;
	double				min_y;
	double				max_y;
	double				jr;
	double				ji;
	double				width;
	double				height;
	int					type;
}						t_data;

typedef	struct			s_val
{
	double				rc;
	double				ic;
	double				rz;
	double				iz;
}						t_val;

void					display_err(int	ret, char *msg);
int						expose_hook(t_thrarg *threads);
int						key_hook(int keycode, t_thrarg *threads);
int						mouse_hook(int button, int x, int y,
	t_thrarg *threads);
int						mouse_hook_2(int button, int x, int y,
	t_thrarg *threads);
int						mouse_hook3(int x, int y, t_thrarg *threads);
int						mouse_hook_4(int button, t_thrarg *threads);
int						get_color(t_env *e, int color);
void					core_mandelbrot_julia(t_thrarg *threads);
void					move_mandelbrot_julia(t_thrarg *threads, int x, int y);
void					set_env_(t_env *e);
t_lims					new_lims(int ymin, int xmin, int ymax, int xmax);
void					init_thr_data(t_thrarg *args, t_env *e);
void					opencl_init(t_env *e);
void					opencl_set_kernels(t_env *e);
void					gpu_mandelbrot(t_env *e);
void					gpu_free_mandel(t_env *e);
t_data					new_data(t_env *e);
void					new_ext(t_env *e);
void					print_to_screen(t_env *e);
void					set_color(t_env *e);
void					set_color_6(t_env *e);
void					set_color_11(t_env *e);
void					set_color16(t_env *e);
void					set_color_bis(t_env *e);
void					set_color_low(t_env *e);
void					print_to_screen(t_env *e);
int						key_hook_2_n(int keycode, t_thrarg *threads);
void					calc_iter_mandel(t_env *e, t_mandel *curent);
void					norm_mandel(pthread_t threads[NUM_THREADS],
	t_thrarg *args);
t_lims					calc_lim(int i, int x, int y);
void					init_mandel_julia(t_mandel *curent, int xmin, int ymin);
void					n_m_y(t_env *e, pthread_t threads[NUM_THREADS],
	t_thrarg *args);
void					set_color_bis_4(t_env *e);
void					calc_iter_burning(t_env *e, t_mandel *curent);
void					opencl_init_bs(t_env *e);
void					opencl_set_kernels_bs(t_env *e);
void					gpu_free_bs(t_env *e);
void					refresh_color_cl(t_env *e);
void					key_p(t_thrarg *threads, t_env *e);
void					key_return(t_thrarg *threads, t_env *e);
void					key_esc(t_env *e);
void					key_f(t_thrarg *threads, t_env *e);
void					refresh_img(t_thrarg *threads, t_env *e);

#endif
