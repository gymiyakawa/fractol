/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:08:03 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/07 15:47:32 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
       mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title );
	   
	   man locations: /usr/share/man/man3/
	   
	   To  use  MiniLibX  func-
       tions,  you'll  need  to
       link your software  with
       the   MiniLibX  library,
       and    several    system
       frameworks:

       -lmlx  -framework OpenGL
       -framework AppKit

       You  may  also  need  to
       specify  the path to the
       MiniLibX library,  using
       the -L flag.
	
	
	next steps:
	Organize and parse for different arguments/sets
	handle color better, opitional color variations by key pressing
	handle zoom and re-initializing the image.
	   */


#include "fractol.h"

int	main ()
{
	t_data 	*f;
	f = malloc(sizeof(t_data));
	if (!f)
		return(-1);
	clean_init(f);
	mlx_setup(f);

	gen_mandelbrot(f);

// holds the screen for command.
	mlx_key_hook(f->win, key_exit, f);
	mlx_loop(f->mlx);

	return (0);
	
}