#define MANDELBROT	1
#define JULIA		2

typedef struct	s_data
{
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	jr;
	double ji;
	double	width;
	double	height;
	int			type;
}				t_data;

typedef struct	s_val
{
	double	rc;
	double ic;
	double rz;
	double	iz;
}				t_val;

__kernel void	calc_points(t_data data, __global t_val *val)
{
	size_t	x;
	size_t	y;
	size_t	size;
	t_val	v;

	x = get_global_id(0);
	y = get_global_id(1);
	size = get_global_size(0);
	v.rc = (data.type == JULIA) ? data.jr : data.min_x +
		(data.max_x - data.min_x) * (double)x / data.width;
	v.ic = (data.type == JULIA) ? data.ji : data.max_y -
		(data.max_y - data.min_y) * (double)y / data.height;
	v.rz = (data.type == JULIA) ? data.min_x +
		(data.max_x - data.min_x) * (double)x / data.width : 0;
	v.iz = (data.type == JULIA) ? data.max_y -
		(data.max_y - data.min_y) * (double)y / data.height : 0;
	val[x + y * size] = v;
}
