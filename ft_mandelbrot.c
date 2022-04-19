#include "ft_fract-ol.h"
#include <stdio.h>

int	ft_is_in_mand_set(t_complex c, int control)
{
	if (control && ((fabs(c.re) < 200) && (fabs(c.im) < 200)))
		return (ft_is_in_mand_set(ft_complex_addition(ft_complex_multiplication(c, c), c), control - 1));
	else
		return (control);
}

t_complex	ft_point_to_complex(float x, float y)
{
	t_complex to_return;

	to_return.re = (x - 800) / 350;
	to_return.im = (y - 400) / 350;
	return (to_return);
}
void	ft_mandelbrot(t_data *data)
{
	int x;
	int y;
	t_complex	op;

	x = 0;
	while (x < 1600)
	{
		y = 0;
		while (y < 800)
		{
			op = ft_point_to_complex(x , y);
			ft_mlx_pixel_put(data, (float)x, (float)y, trgb(0, 0, 0, ft_is_in_mand_set(op, 255)));
			y++;
		}
		x++;
	}
}
