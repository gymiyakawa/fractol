/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:22:51 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/20 11:29:34 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// checks endianess of system. returning 1 in case of little
// endianess or 0 if big.

int	ft_is_little_endian(void)
{
	int	n;

	n = 1;
	if (*(char *)&n == 1)
		return (1);
	else
		return (0);
}

// 	function destroys image, destroys window, and free any
// 	malloced pointers. Prints a farewell message at the end.

void	clean_exit(t_data *f)
{
	if (f->img_data->img)
	{
		mlx_destroy_image(f->mlx, f->img_data->img);
		free(f->img_data);
	}
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->color)
		free(f->color);
	ft_printf("\nPsychodelic trip ended. See you next time!\nx)\n");
	exit(0);
}

// functions that alters center thorugh center_i/r based on zoom value
// rough overview of the calculation:
// calculate the center of the cartezian plane (different from 
// what the pixel grid is), following that calculate the right border
// offset (max r) by adding the current center minus the center times 
// zoom. Your new right border position will have to be moved half that
// 0.1, the other half is move by the other border.
// does this even make sense?

void	mouse_zoom(t_data *f, double zoom, int x, int y)
{
	(void)x;
	(void)y;
	f->center_r = f->min_r - f->max_r;
	f->center_i = f->max_i - f->min_i;
	f->max_r = f->max_r + (f->center_r - zoom * f->center_r) / 2;
	f->min_r = f->max_r + zoom * f->center_r;
	f->min_i = f->min_i + (f->center_i - zoom * f->center_i) / 2;
	f->max_i = f->min_i + zoom * f->center_i;
	return ;
}

// moves the image according to the key pushed. "0.1" is 
// an arbritary value, can be increased if you want
// bigger move increments.

void	move(t_data	*f, char direction)
{
	f->center_r = f->min_r - f->max_r;
	f->center_i = f->min_i - f->max_i;
	if (direction == 'U')
	{
		f->min_i -= f->center_i * 0.1;
		f->max_i -= f->center_i * 0.1;
	}
	if (direction == 'D')
	{
		f->min_i += f->center_i * 0.1;
		f->max_i += f->center_i * 0.1;
	}
	if (direction == 'R')
	{
		f->min_r -= f->center_r * 0.1;
		f->max_r -= f->center_r * 0.1;
	}
	if (direction == 'L')
	{
		f->min_r += f->center_r * 0.1;
		f->max_r += f->center_r * 0.1;
	}
	return ;
}
	// function uses the img address given by mlx. It finds the
	// pixel relative to x,y coordinates by offseting, 
	// in memory, y * the legnth of the line (thius finding the right line) plus
	// x * the bits per pixel / 8 (to find the number of bytes). And then
	// changes the value of that pixel to the int-coded color.

void	my_px_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}
