/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:48:41 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/20 13:41:13 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* 
								The Julia set:
	The Julia and Mandelbrot set are very related. Mandelbrot (the mathmathician)
	devised his fractal while studying the Julia set. And it is a map for 
	when the Julia set becomes connected and disconnected, for a set value
	of 'c'.
	
	The Julia set uses pretty much the same formula as the Mandelbrot but
	instead of checking every pixel to see if it is a part of the set, we 
	alternate the coordinates themselves. For every point in the complex
	plane there is a different shape for the Julia set.
	
	If that point is in the Mandelbrot set, the shape will be a single shape.
	If not, then it will be isolated island that recurse a pattern into inifinty
	If it's at the border it will take shapes similar to the ones we see in
	the Mandelbrot set.
	
							Julia set formula:
							
							f(z) = z^n + c
							where c is constant.
							
							In pseudocode:
	while (zx * zx + zy * zy < R**2  AND  iteration < max_iteration) 
    {
        xtemp = zx * zx - zy * zy
        zy = 2 * zx * zy  + cy 
        zx = xtemp + cx

	source: https://en.wikipedia.org/wiki/Julia_set 

*/
void	gen_julia(t_data *f)
{
	int		x;
	int		y;
	double	pr;
	double	pi;

	if (!f)
		return ;
	y = -1;
	while (++y < HEIGHT)
	{
		pi = f->max_i + ((double)y * (f->min_i - f->max_i) / HEIGHT);
		x = -1;
		while (++x < LENGTH)
		{
			pr = f->min_r + ((double)x * (f->max_r - f->min_r) / LENGTH);
			if (is_julia(pr, pi, f) == 0)
				my_px_put(f->img_data, x, y, make_color(f));
			else
				my_px_put(f->img_data, x, y, create_trgb(0, 0, 0, 0));
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img_data->img, 0, 0);
	return ;
}

int	is_julia(double zr, double zi, t_data	*f)
{
	double	tmp;
	int		i;

	i = 0;
	while (i++ < MAX_ITERATION + f->resolution_shift)
	{
		if ((zr * zr + zi * zi) > 4)
		{
			f->count = i;
			return (0);
		}
		tmp = zr * zr - zi * zi;
		zi = 2 * zr * zi + f->julia_shifty;
		zr = tmp + f->julia_shiftx;
	}
		f->count = i;
	return (1);
}

void	julia_shift(int x, int y, t_data *f)
{
	f->julia_shiftx = f->min_r + (double)x * (f->max_r - f->min_i) / LENGTH;
	f->julia_shifty = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
	printf("New Julia Parameters: x = %f, y = %f\n", \
			f->julia_shiftx, f->julia_shifty);
	return ;
}
