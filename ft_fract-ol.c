#include "ft_fract-ol.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
//	t_point start;
//	t_point end;
//	t_point c;
	t_data	img;
	
//	start.x = 855;
//	start.y = 0;
//	end.x = 1919;
//	end.y = 900;
//	c.x = 0;
//	c.y = 900;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1600, 800, "Hello world!");
	img.img = mlx_new_image(mlx, 1600, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
				&img.endian);
//	ft_mlx_line_segment(&img, start, end, trgb(0, 255, 255, 0));
//	ft_mlx_line_segment(&img, end, start, trgb(0, 0, 255, 255));
//	ft_koch_triangle(&img, c, end, start, trgb(0, 255, 255, 0), 6); 
	ft_mandelbrot(&img);	
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
