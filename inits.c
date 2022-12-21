/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:50:11 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/21 10:58:46 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// initializes all struct variables to 0 or NULL.
t_data	clean_init(void)
{
	t_data	f;

	f.mlx = NULL;
	f.win = NULL;
	f.min_r = 0;
	f.max_r = 0;
	f.min_i = 0;
	f.max_i = 0;
	f.count = 0;
	f.color_shift = 1;
	f.resolution_shift = 0;
	f.set = 0;
	f.center_i = 0;
	f.center_r = 0;
	f.julia_shiftx = 0;
	f.julia_shifty = 0;
	f.args = NULL;
	f.img_data = x_calloc(sizeof(t_img));
	f.color = x_calloc(sizeof(t_color));
	return (f);
}

	// initializes the mlx interfaces: Connection, window and image.
	// 
	// Following that, finds the address of the first bit in memory 
	// corresponding to the image.
	// mlx_get_data_addr fills in the info relative to "bits per pixel", 
	// "size_line" and "endian" to their respective provided addresses.
	// 			from /usr/share/man/man3/mlx_new_image.1 :
	// "bits_per_pixel will be filled with the number of bits needed to 
	// represent a pixel color (also called the depth of the image) size_line
	//  is the number of bytes used to store one line of the image in memory.
	// This information is needed to move from one line to another in the image.
	// mlx_get_data_addr returns a char * address that represents the begining
	// of the memory area where  the  image is  stored.  From  this  adress, the
	// first bits_per_pixel bits represent the color of the first pixel in the
	// first line of the image. The second group of bits_per_pixel bits
	// represent the second  pixel  of  the  first line, and so on.  Add
	// size_line to the adress to get the begining of the second line. You can
	// reach any pixels of the image that way."

void	mlx_setup(t_data	*f)
{
	f->mlx = mlx_init();
	if (f->mlx == NULL)
	{
		ft_printf("MLX initialization error.\n");
		clean_exit (f);
		return ;
	}
	win_gen(f);
	f->img_data->img = mlx_new_image(f->mlx, LENGTH, HEIGHT);
	if (!f->img_data->img)
	{
		clean_exit(f);
		ft_printf("MLX image creation error.\n");
		return ;
	}
	f->img_data->addr = mlx_get_data_addr(f->img_data->img, &f->img_data->bpp, \
							&f->img_data->line_len, &f->img_data->endian);
	return ;
}

// creates MLX window and names it according to the correct fractal set.
void	win_gen(t_data *f)
{
	if (f->set == MANDELBROT)
	{
		f->win = mlx_new_window(f->mlx, LENGTH, HEIGHT, "Mandelbrot Set");
		if (f->win == NULL)
		{
			clean_exit(f);
			ft_printf("MLX window creation error.\n");
			exit(-1);
		}
	}
	if (f->set == JULIA)
	{
		f->win = mlx_new_window(f->mlx, LENGTH, HEIGHT, "Julia Set");
		if (f->win == NULL)
		{
			clean_exit(f);
			ft_printf("MLX window creation error.\n");
			exit(-1);
		}
	}
	return ;
}

// lists the available commands for this program.

void	command_list(t_data *f)
{
	ft_printf("Available commands:\n");
	ft_printf("WASD: move screen\n");
	ft_printf("Mouse Wheel: Zoom in / Zoom out\n");
	ft_printf("ESC: quits program\n");
	ft_printf("Left Shift: color shift\n");
	ft_printf("Left Alt: cycle through resolution (max iteration)\n");
	ft_printf("<!> +iterations = +resolution = -rendering speed <!>\n\n");
	if (f->set == JULIA)
	{
		ft_printf("For Julia sets:\nDefault parameters = %d, %d (image \
				center)\n", HEIGHT / 2, LENGTH / 2);
		ft_printf("Right Click: change parameter to the current mouse x, y\n\n");
	}
	return ;
}
	// Maps the min and max values for x,y in the complex plane, x being the
	// real portion and y being the imaginary one. That is what makes
	// translating complex numbers to pixel positions. They are realted to the
	// LENGHT and HEIGHT ratio to avoid deformation when screen dimensions
	// change.
	// changing to a non-square aspect ration will make the fractal start 
	// uncentered, but the proportions will remain correct.
	// The values of the grid are arbritary, -2 to 2 are the ones I found 
	// to work best. As long as they remain the same for r and i the size of
	// the grid will only affect the size of the fractal at first iteration.
	// Changing the ratio would likely produce distortion.

void	set_minmax(t_data *f)
{
	f->min_r = -2;
	f->max_r = f->min_r * -1 * LENGTH / HEIGHT;
	f->min_i = -2;
	f->max_i = f->min_i * -1 * HEIGHT / LENGTH;
	return ;
}
