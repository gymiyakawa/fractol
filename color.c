/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:03:15 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/20 14:55:15 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// function must: increment the value of color_shift, loop
// back if max count is reached (currently, 5)

void	shift_color(t_data *f)
{
	f->color_shift += 1;
	if (f->color_shift > 5)
		f->color_shift = 1;
	return ;
}

// changes the values of r g b in an arbritary way
// to get new color combinations. This is the place
// to fiddle with if you want to change colors.

void	apply_shift(t_data *f)
{
	if (f->color_shift == 1)
	{
		f->color->r += 150;
		f->color->b += 10;
	}
	else if (f->color_shift == 2)
	{
		f->color->r += 70;
		f->color->b += 70;
	}
	else if (f->color_shift == 3)
		f->color->g += 75;
	else if (f->color_shift == 4)
		f->color->b += 140;
	else
	{
		f->color->b = 75;
		f->color->g += 75;
	}
	return ;
}

	// get color works by running count through a color "line".
	//
	// Line progression is sequential following the color spectrum
	// from red to violet.
	// Position 0 = red = 255, 0, 0
	// Position 255 = yellow = 255, 255, 0
	// Position 510 = green = 0, 255, 0
	// ...
	// Final position 1275 = violet = 255, 0, 255
	//
	// The idea is to find where in this spectrum "color value" lies 
	// and return the int related to that position
	//
	// ie. if color_value = 285
	// value of red at position 285:
	// 255 - (285 - 255) = 225 = a lighter shade of red.
	//
	// if the value exceeds 1275 (or 6 iterations of 255),
	// return 255 on all colors = white

int	get_red(int color_value)
{
	if (color_value >= 0 && color_value <= 255)
		return (255);
	else if (color_value > 255 && color_value <= 510)
		return (255 - (color_value - 255));
	else if (color_value > 510 && color_value <= 1020)
		return (0);
	else if (color_value > 1020 && color_value <= 1275)
		return (color_value - 1020);
	else
		return (255);
}

int	get_green(int color_value)
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

int	get_blue(int color_value)
{
	if (color_value >= 0 && color_value <= 510)
		return (0);
	if (color_value > 510 && color_value <= 765)
		return (color_value - 510);
	else
		return (255);
}
