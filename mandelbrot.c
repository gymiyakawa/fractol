/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:09:50 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/20 14:51:16 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 						The Mandelbrot Formula.
// 					From wikipedia, in pseudocode
// for each pixel (Px, Py) on the screen do
//   x0 := scaled x coordinate of pixel (scaled to lie in the
// 	 Mandelbrot X scale (-2.00, 0.47))
//   y0 := scaled y coordinate of pixel (scaled to lie in the
// 	 Mandelbrot Y scale (-1.12, 1.12))
//     x := 0.0
//     y := 0.0
//     iteration := 0
//     max_iteration := 1000
//     while (x*x + y*y ≤ 2*2 AND iteration < max_iteration) do
//         xtemp := x*x - y*y + x0
//         y := 2*x*y + y0
//         x := xtemp
//         iteration := iteration + 1

#include "fractol.h"

// 		This functions runs the Mandelbrot formula in order to determine
// if a pixel is part of the set.
// 		MAX_ITERATION is modified by a variable that allows the user to
// change the "resolution" of the fractal. The more iterations a pixel
// is put through, the more accurate the fractal but also the number of
// calculations is also dramatically increased.
// 		4 is considered to be the threshold value to determine if a 
// point if part of the Mandelbrot set or not. If the value is
// ever past that, the function returns but also keeps track of
// how many iterations it took to get to that point as that will
// determine color assignment.

int	is_mandelbrot(double cr, double ci, t_data *f)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	i = 0;
	zr = 0;
	zi = 0;
	while (i <= MAX_ITERATION + f->resolution_shift)
	{
		if ((zr * zr + zi * zi) > 4.0)
		{
			f->count = i;
			return (0);
		}
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		i++;
	}
			f->count = i;
	return (1);
}

// The functions loops through all lines and colums (y and x, respc.)
// for each pixel, it runs the equation a set number of time (MAX_ITER)
// if the value of the equation "escapes" towards infinity, the pixel
// is said to be outside the Mandelbrot set and will be assigned a color.
// Else, if it remains contained, it will be considered to be a part of
// the set and will be colored black. After going through all pixels
// the function pushes the image to the window.

void	gen_mandelbrot(t_data *f)
{
	int		x;
	int		y;
	double	pr;
	double	pi;

	y = -1;
	while (++y < HEIGHT)
	{
		pi = f->max_i + ((double)y * (f->min_i - f->max_i) / HEIGHT);
		x = -1;
		while (++x < LENGTH)
		{
			pr = f->min_r + ((double)x * (f->max_r - f->min_r) / LENGTH);
			if (is_mandelbrot(pr, pi, f) == 0)
				my_px_put(f->img_data, x, y, make_color(f));
			else
				my_px_put(f->img_data, x, y, create_trgb(0, 0, 0, 0));
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img_data->img, 0, 0);
	return ;
}
