/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:22:51 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/07 16:48:07 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// checks endianess of system. returning 1 in case of little
// endianess or 0 if big.


int	ft_is_little_endian()
{
	int n;
	n = 1;
	if (*(char *)&n == 1)
		return (1);
	else
		return (0);
}

// create a function to clean exit

/*
	function must: destroy image, destroy window, end loop, destroy display
	and free its pointer. in this order.
*/
void clean_exit (t_data *f)
{
	if (f->img_data->img)
	{
		mlx_destroy_image(f->mlx, f->img_data->img);
		free(f->img_data);
	}
	if (f->win)
	{
		mlx_destroy_window(f->mlx, f->win);
	}
	if (f->mlx)
	{
		free(f);
	}
	exit(0);
}

// function to clean exit on ESC key

int key_exit (int keycode, t_data *f)
{
	// printf("%d\n", keycode);
	if (keycode == 53)
		clean_exit(f);
	if (keycode == 257)
		shift_color(f);
	return (0);
}

// draws line given the indicated values.

int draw_line(void *mlx_ptr, void *n_window, int beginX,\
					int beginY, int endX, int endY, int color)
	{
		double deltaX;
		double deltaY;
		
		deltaX = endX - beginX;
		deltaY = endY - beginY;
		
		int pixels;
		pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
		
		deltaX /= pixels;
		deltaY /= pixels;
	
		double pixelX;
		double pixelY;
		
		pixelX = beginX;
		pixelY = beginY;
		while (pixels)
		{
			mlx_pixel_put(mlx_ptr, n_window, pixelX, pixelY, color);
			pixelX += deltaX;
			pixelY += deltaY;
			--pixels;
		}
		return (0);
	}

