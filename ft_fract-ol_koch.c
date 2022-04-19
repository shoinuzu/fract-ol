#include "ft_fract-ol.h"

void	ft_mlx_triangle(t_data *data, t_point a, t_point b, t_point c, int color)
{
	ft_mlx_line_segment(data, a, b, color);
	ft_mlx_line_segment(data, b, c, color);
	ft_mlx_line_segment(data, a, c, color);
}

t_point	ft_midle_point(t_point a, t_point b)
{
	t_point to_return;

	if (a.x > b.x)
		to_return.x = b.x + (a.x - b.x) / 2;
	else
		to_return.x = a.x + (b.x - a.x) / 2;
	if (a.y > b.y)
		to_return.y = b.y + (a.y - b.y) / 2;
	else
		to_return.y = a.y + (b.y - a.y) / 2;
	return (to_return);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

void	ft_koch_triangle(t_data *data, t_point a, t_point b, t_point c, int color, int iterations)
{
	ft_mlx_triangle(data, a, b, c, color);
	if (iterations >= 0)
	{
		ft_koch_triangle(data, ft_midle_point(a, b), ft_midle_point(b, c), b, color, iterations - 1);
		ft_koch_triangle(data, ft_midle_point(a, c), ft_midle_point(a, b), a, color, iterations - 1);
		ft_koch_triangle(data, ft_midle_point(a, c), c, ft_midle_point(b, c), color, iterations - 1);
	}
}
