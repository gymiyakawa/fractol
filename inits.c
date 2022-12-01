/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:50:11 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/01 15:27:31 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// initializes all struct variables to 0 or NULL.
void clean_init(t_data *f)
{
	f->mlx = NULL;
	f->img = NULL;
	f->win = NULL;
	f->img_addr = NULL;
	f->min_r = 0;
	f->max_r = 0;
	f->min_i = 0;
	f->max_i = 0;
	f->bits_per_pixel = 0;
	f->size_line = 0;
	f->endian = 0;
	f->count = 0;
	return;
}


// initializes the connection to the monitor and checks for errors
void mlx_setup(t_data *f)
{
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		return;

// opens a new window and checks for erros
	f->win = mlx_new_window(f->mlx, LENGTH, HEIGHT, "new fractal");
	if (f->win == NULL)
	{
		free (f->mlx);
		return;
	}

// initializes a new image in MLX
	f->img = mlx_new_image(f->mlx, LENGTH, HEIGHT);
		if (!f->img)
			return;

 	// finds the address of the first bit in memory corresponding to the image. Fills in info relative to "bits per pixel", 
	// "size_line" and "endian" to their respective provided addresses.

/*									from /usr/share/man/man3/mlx_new_image.1
		"bits_per_pixel will be filled with the number of bits needed to represent a pixel
		color  (also called the depth of the image).  size_line is the number of bytes used to store one line of the
       	image in memory.  This information is needed to move from one line to another in the  image.

		mlx_get_data_addr returns a char * address that represents the begining of the memory area where  the  image
		is  stored.  From  this  adress, the first bits_per_pixel bits represent the color of the first pixel in the
		first line of the image. The second group of bits_per_pixel bits represent the second  pixel  of  the  first
		line, and so on.  Add size_line to the adress to get the begining of the second line. You can reach any pix-
		els of the image that way."
*/
	f->img_addr = mlx_get_data_addr(f->mlx, &f->bits_per_pixel, &f->size_line, &f->endian);
	return;
}
