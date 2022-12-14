/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:09:50 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/14 13:32:47 by gmiyakaw         ###   ########.fr       */
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

int is_mandelbrot (double cr, double ci, t_data *f)
{
	 double zr;
	 double zi;
	 double tmp;
	 int	i;
	 
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

void	gen_mandelbrot(t_data *f)
{
	int 	x;
	int 	y;
	double 	pr;
	double 	pi;
	int trgb;

	y = 0;
	while (y < HEIGHT)
	{
		pi = f->max_i + ((double)y * (f->min_i - f->max_i) / LENGTH);
		x = 0;
		while (x < LENGTH)
		{
			pr = f->min_r + ((double)x * (f->max_r - f->min_r) / HEIGHT);
			if (is_mandelbrot(pr, pi, f) == 0)
			{
				trgb = make_color(f);
				my_px_put(f->img_data, x, y, trgb);
			}
			else
			{
				trgb = create_trgb(0, 0, 0, 0);
				my_px_put(f->img_data, x, y, trgb);
			}
			x++;
		}
		y++;
	}
    mlx_put_image_to_window(f->mlx, f->win, f->img_data->img, 0, 0);
	return;
}


	// loop through all x pixels in line 0. go down a line, reset x, repeat until max x && max y 

	// while looping, compare each pixel position with the formula, run it for a determined number of 
	// iterations (MAX ITER). If the result is ever an "escape" value (ie. > 2), skip to the next pixel.
	//  else: putpixel into the img.

	// put the image to window once done. 

