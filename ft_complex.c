#include "ft_fract-ol.h"

t_complex	ft_complex_addition(t_complex c1, t_complex c2)
{
	t_complex	to_return;

	to_return.re = c1.re + c2.re;
	to_return.im = c1.im + c2.im;
	return (to_return);
}

t_complex	ft_complex_multiplication(t_complex c1, t_complex c2)
{
	t_complex	to_return;

	to_return.re = (c1.re * c2.re) - (c1.im * c2.im);
	to_return.im = (c1.im * c2.re) + (c1.re * c2.im);
	return (to_return);	
}
