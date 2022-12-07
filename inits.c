/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:50:11 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/07 16:37:28 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// initializes all struct variables to 0 or NULL.
void clean_init(t_data *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->min_r = 0;
	f->max_r = 0;
	f->min_i = 0;
	f->max_i = 0;
	f->count = 0;
	f->color_shift = 1;
	f->img_data = malloc(sizeof(t_img));
		if (!f->img_data)
		{
			perror("Error: ");
			return;
		}
	f->img_data->img = NULL;
	f->img_data->addr = NULL;
	f->img_data->bpp = 0;
	f->img_data->line_len = 0;
	f->img_data->endian = 0;
	return;
}

// make proper error messages. This means these functions shouldnt be void funtions


// initializes the connection to the monitor and checks for errors
void mlx_setup(t_data *f)
{
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		{
			perror("Error: ");
			return;
		}
// opens a new window and checks for erros
	f->win = mlx_new_window(f->mlx, LENGTH, HEIGHT, "new fractal");
	if (f->win == NULL)
	{
		free (f->mlx);
		perror("Error: ");
		return;
	}

// initializes a new image in MLX
	f->img_data->img = mlx_new_image(f->mlx, LENGTH, HEIGHT);
		if (!f->img_data->img)
		{
			perror("Error: ");
			return;
		}
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
	f->img_data->addr = mlx_get_data_addr(f->img_data->img, &f->img_data->bpp, \
							&f->img_data->line_len, &f->img_data->endian);
	return;
}
