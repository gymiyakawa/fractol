/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:08:03 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/01 15:23:17 by gmiyakaw         ###   ########.fr       */
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
	
	
	steps: create visual link, create windows and create image. 
	go pixel by pixel on the image 
	
	   */


#include "fractol.h"

int	main ()
{
	t_data 	f;
	clean_init(&f);
	mlx_setup(&f);

	gen_mandelbrot(&f);


// holds the screen for command.
	mlx_loop(f.mlx);

	return (0);
	
}