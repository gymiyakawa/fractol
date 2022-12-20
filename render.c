/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:22:34 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/20 14:51:59 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// checks for the correct argument and sets f->set to the chosen
// fractal. If no avaiable option is given, displays an error
// message and exits cleanly.

void	sort_fractal(t_data *f, char *arg)
{
	arg = ft_str_tolower(arg);
	if (ft_strcmp(arg, "mandelbrot") == 0)
		f->set = MANDELBROT;
	else if (ft_strcmp(arg, "julia") == 0)
		f->set = JULIA;
	else
	{
		ft_printf("Error: no such fractal\n");
		ft_printf("Available fractals: Mandelbrot, Julia\n");
		clean_exit(f);
	}
	return ;
}

// "listens" for events, generates a fractal based on the 
//  value of f->set

int	generate_fractal(t_data *f)
{
	handle_events(f);
	if (f->set == MANDELBROT)
		gen_mandelbrot(f);
	if (f->set == JULIA)
		gen_julia(f);
	return (0);
}

// bit shifts the ints into the correct position for color coding
// bits for color are coded: TTT RRR GGG BBB
// ranging from 000 to 255

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// 		gets the color values of r g b. Uses count as a
// way to set where in the spectrum each primary color should 
// land. Count if multiplied so it accounts for greater range
// 15 is an arbritary value that can be changed if more less 
// range is desired.
// 		The function then applies any color shift and assembles
// the int using create_trgb.

int	make_color(t_data *f)
{
	int	color_value;

	color_value = f->count * 15;
	f->color->r = get_red(color_value);
	f->color->g = get_green(color_value);
	f->color->b = get_blue(color_value);
	apply_shift(f);
	return (create_trgb(0, f->color->r, f->color->g, \
			f->color->b));
}
