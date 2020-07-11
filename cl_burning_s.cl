#define COLOR_SET	9
#define BURNING     0

typedef struct	s_val
{
	double	rc;
	double	ic;
	double	rz;
	double	iz;
}				t_val;

typedef struct	s_data
{
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	jr;
	double	ji;
	double	width;
	double	height;
	int		type;
}				t_data;

void	init(double *zr, double *zi, double *cr, double *ci, t_val val);
int		calc(double zr, double zi, double rc, double ic, int iter);
t_val	point(t_data data, size_t x, size_t y);
void	cpy(__global t_val *vals, __local double *p);

t_val			point(t_data data, size_t x, size_t y)
{
	t_val	v;

	v.rc = data.min_x + (data.max_x - data.min_x) * (double)x / data.width;
	v.ic = data.max_y - (data.max_y - data.min_y) * (double)y / data.height;
	v.rz = 0;
	v.iz = 0;
	return (v);
}

__kernel void	init_vals(__global t_data *data, __global t_val *vals)
{
	int		x;
	int		y;
	int		l;
	
	x = get_global_id(0);
	y = get_global_id(1);
	l = get_global_size(0);
	vals[x + y * l].rc = data->min_x + (data->max_x - data->min_x) * (double)x / (double)data->width;
	vals[x + y * l].ic = data->max_y - (data->max_y - data->min_y) * (double)y / (double)data->height;
	vals[x + y * l].rz = 0;
	vals[x + y * l].iz = 0;
}

void			cpy(__global t_val *vals, __local double *p)
{
	int		i;

	i = -1;
	while (++i < 16)
	{
		p[2 *i] = vals[i].rz;
		p[2 *i + 1] = vals[i].iz;
	}
}

__kernel void	burning_ship(__global t_val *vals, __global int *buff,
			int iter, __global int *colors, int num_colors)
{
	int				x;
	int				y;
	int				l;
	double			rz;
	double			iz;
	double			rc;
	double			ic;
	int				i;
	double			z;

	x = get_global_id(0);
	y = get_global_id(1);
	l = get_global_size(0);
	rc = (vals + x + y * l)->rc;
	ic = (vals + x + y * l)->ic;
	rz = (vals + x + y * l)->rz;
	iz = (vals + x + y * l)->iz;
	i = 0;
	while(rz * rz + iz * iz <= 4.0 && i < iter)
	{
		z = rz * rz - iz * iz + rc;
		rz = (rz > 0.0) ? rz : -rz;
		iz = (iz > 0.0) ? iz : -iz;
		iz = 2 * rz * iz + ic;
		rz = z;
		++i;
	}
	buff[x + y * l] = i == iter ? 0 : colors[i % num_colors];
}
