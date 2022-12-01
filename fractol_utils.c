/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:22:51 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/01 16:26:20 by gmiyakaw         ###   ########.fr       */
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

