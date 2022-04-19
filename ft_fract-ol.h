#include <mlx.h>
#include <math.h>

typedef	struct	s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}		t_data;

typedef	struct	s_point 
{
	float x;
	float y;
}		t_point;

typedef struct	s_complex
{
	float re;
	float im;
}		t_complex;

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_mlx_line_segment(t_data *data, t_point start, t_point end, int color);
void	ft_mlx_square(t_data *data, t_point up_left, t_point down_rigth, int color);
void	ft_mlx_triangle(t_data *data, t_point a, t_point b, t_point c, int color);
void	ft_koch_triangle(t_data *data, t_point a, t_point b, t_point c, int color, int iterations);
int	trgb(int t, int r, int g, int b);
t_complex	ft_complex_multiplication(t_complex c1, t_complex c2);
int	ft_is_in_mand_set(t_complex c, int control);
void	ft_mandelbrot(t_data *data);
t_complex	ft_complex_addition(t_complex c1, t_complex c2);
