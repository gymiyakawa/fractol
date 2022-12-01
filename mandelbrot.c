/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:09:50 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/01 16:22:48 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 
// a function that creates the mandelbrot fractal
 

// From wikipedia
// for each pixel (Px, Py) on the screen do
//     x0 := scaled x coordinate of pixel (scaled to lie in the Mandelbrot X scale (-2.00, 0.47))
//     y0 := scaled y coordinate of pixel (scaled to lie in the Mandelbrot Y scale (-1.12, 1.12))
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
#include <stdio.h>

int is_mandelbrot (double cr, double ci, t_data *f)
{
	 double zr;
	 double zi;
	 double tmp;
	 int	i;
	 
	 i = 0;
	 zr = 0;
	 zi = 0;
			while (i <= MAX_ITERATION)
			{
				if ((zr * zr + zi * zi) > 2.0)
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

void	gen_mandelbrot(t_data *f)
{
	int 	x;
	int 	y;
	double 	pr;
	double 	pi;

	x = 0;
	y = 0;
	f->min_r = -2.0;
	f->max_r = 2.0;
	f->max_i = 2.0;
	f->min_i = -2.0;
	pr = f->min_r + (double)x * (f->max_r - f->min_r) / LENGTH;
	pi = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;

	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= LENGTH)
		{
			if (is_mandelbrot(pr, pi, f) == 0)
				mlx_pixel_put(f->mlx, f->win, x, y, 0x000000);
			else
				mlx_pixel_put(f->mlx, f->win, x, y, 0x0000FF);
			x++;
		}
		y++;
	}
	return;
}


	// loop through all x pixels in line 0. go down a line, reset x, repeat until max x && max y 

	// while looping, compare each pixel position with the formula, run it for a determined number of 
	// iterations (MAX ITER). If the result is ever an "escape" value (ie. > 2), skip to the next pixel.
	//  else: putpixel into the img.

	// put the image to window once done. 

