/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:09:50 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/07 16:27:01 by gmiyakaw         ###   ########.fr       */
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

// void my_px_put(t_data *f, int x, int y, int color)
// {
// 	char *dst;

// 	dst = f->img_data->img_addr + (y * f->img_data->line_len + x * (f->img_data->bpp / 32));
// 	*(unsigned int *)dst = color;
// }


	// function uses the img address given by mlx. It finds the pixel relative to x,y coordinates
	// by offseting, in memory, y * the legnth of the line (thius finding the right line) plus
	// x * the bits per pixel / 8 (to find the number of bytes). And then changes the value of 
	// that pixel to the int-coded color.

void	my_px_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;

}

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
	f->min_r = - 2.0;
	f->max_r = 2;
	f->min_i = - 2.0;
	f->max_i = 2;

	while (y < HEIGHT)
	{
		x = 0;
		while (x < LENGTH)
		{
			pr = f->min_r + (double)x * (f->max_r - f->min_r) / 1500;
			pi = f->max_i + (double)y * (f->min_i - f->max_i) / 1500;
			if (is_mandelbrot(pr, pi, f) == 0)
				{
				trgb = make_color(f->count, &f->color_shift);
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

