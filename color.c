/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:03:15 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/14 16:38:23 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

	// bit shifts the ints into the correct position for color coding
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// function must: increment the value of color_shift, destroy the current image,
// create a new one and push it to the window.

void	shift_color(t_data *f)
{
	if (f->color_shift >= 5)
		f->color_shift = 1;
	f->color_shift += 1;
	apply_shift(f);
	return;
}

void	apply_shift(t_data *f)
{
	if (f->color_shift == 1)
	{
		f->color->r += 50;
		f->color->b += 50;
	}
	if (f->color_shift == 2)
	{
		f->color->r += 50;
		f->color->b += 50;
	}
	if (f->color_shift == 3)
		f->color->g += 50;
	if (f->color_shift == 4)
		f->color->b += 50;
	if (f->color_shift == 5)
	{
		f->color->r = 0;
		f->color->g += 75;
	}
}

int	make_color(t_data *f)
{
	int	color_value;

	color_value = f->count * 10;
	f->color->r = get_red(color_value);
	f->color->g = get_green(color_value);
	f->color->b = get_blue(color_value);
	// apply_shift(f)
	return (create_trgb(0, f->color->r, f->color->g, \
			f->color->b));
}

/*
	get color works by running count through a color "line".
	0 = red = 255, 0, 0;
	255 = yellow = 255, 255, 0;
	510 = green = 0, 255, 0; 
	..
	..
	from red(255,0,0) to violet(0,255,255)
	it finds where in this spectrum "color value" lies and 
	returns the int related to that position
	ie. if color_value = 285
	red = 255 - (285 - 255) = 225 = a lighter shade of red. 

	if the value exceeds 1275 (or 6 iterations of 255), 
	return 255 on all colors = white
*/

int get_red(int color_value)
{
	if (color_value >= 0 && color_value <= 255)
		return(255);
	else if (color_value > 255 && color_value <= 510)
		return (255 - (color_value - 255));
	else if (color_value > 510 && color_value <= 1020)
		return (0);
	else if (color_value > 1020 && color_value <= 1275)
		return (color_value - 1020);
	else
		return (255);
}

int get_green(int color_value)
{
	if (color_value >= 0 && color_value <= 255)
		return (color_value);
	else if (color_value > 255 && color_value <= 765)
		return (255);
	else if (color_value > 765 && color_value <= 1020)
		return (255 - (color_value - 765));
	else if (color_value > 1020 && color_value <= 1275)
		return (0);
	else
		return (255);
}

int get_blue(int color_value)
{
	if (color_value >= 0 && color_value <= 510)
		return (0);
	if (color_value > 510 && color_value <= 765)
		return (color_value - 510);
	else
		return (255);
}