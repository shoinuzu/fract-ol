#include "ft_fract-ol.h"
#include <stdio.h>

void	ft_mlx_square(t_data *data, t_point up_left, t_point down_rigth, int color)
{
	int c;

	c = up_left.x;
	while (c < down_rigth.x)
	{
		ft_mlx_pixel_put(data, c, up_left.y, color);
		c++;
	}
	c = up_left.y;
	while (c < down_rigth.y)
	{
		ft_mlx_pixel_put(data, up_left.x, c, color);
		c++;
	}
	c = down_rigth.x;
	while (c > up_left.x)
	{
		ft_mlx_pixel_put(data, c, down_rigth.y, color);
		c--;
	}
	c = down_rigth.y;
	while (c > up_left.y)
	{
		ft_mlx_pixel_put(data, down_rigth.x, c, color);
		c--;
	}
}

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_mlx_line_segment(t_data *data, t_point start, t_point end, int color)
{
	double	h;
	double	l;
	int control;
	double	ratio;

	h = end.y - start.y;
	l = end.x - start.x;
	control = 0;
	if (l == 0)
	{
		while (fabs((float)control) - fabs(h))
		{
			ft_mlx_pixel_put(data, start.x, (start.y + control), color);
			if (h < 0)
				control--;
			else
				control++;
		}
		return ;
	}
	ratio = h / l;
	if (ratio == 0)
	{
		while (fabs((float)control) < fabs(l))
		{
			ft_mlx_pixel_put(data, (start.x + control), start.y, color);
			if (l < 0)
				control--;
			else 
				control++;
		}
		return ;
	}
	while ((h >= 0) && (l >= 0) && (fabs((float)control) < fabs((float)l)))
	{
		ft_mlx_pixel_put(data, (start.x + control), (start.y + control * ratio), color);
		control++;
	}
	while ((h < 0) && (l >= 0) && (fabs((float)control) < fabs((float)l)))
	{
		ft_mlx_pixel_put(data, (start.x + control), (start.y + control * ratio), color);
		control++;
	}
	while ((h >= 0) && (l < 0) && (fabs((float)control) < fabs((float)l)))
	{
		ft_mlx_pixel_put(data, (start.x + control), (start.y + control * ratio), color);
		control--;
	}
	while ((h < 0) && (l < 0) && (fabs((float)control) < fabs(l)))
	{
		ft_mlx_pixel_put(data, (start.x + control), (start.y + control * ratio), color);
		control--;
	}
}

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
