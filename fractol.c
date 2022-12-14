/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:08:03 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/14 16:40:14 by gmiyakaw         ###   ########.fr       */
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
	Make the Julia Set
	handle zoom and re-initializing the image.
	map and set all the possible events: clicking the x, minimizing etc
	   */


#include "fractol.h"

int	main (int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "error: missing name", 19);
		return (-1);
	}
	t_data 	f;

	// parse and handle arguments;
	f = clean_init();
	sort_fractal(&f, av[1]);
	mlx_setup(&f);

	// displays available commands
	command_list();



// need to create a hook loop, have the other hooks inside of it.
//	it should loop the render/generate function constantly.
// gotta figure out a way for it to always render the right one.
// should be smoother and maybe it will solve the mouse problem.

//	mlx hook loop ( rendenring function)
					// inside the rendenring function: all the hoooks

// holds the screen for command.

	mlx_loop_hook(f.mlx, &generate_fractal, &f);
	// mlx_mouse_hook(f.win, handle_mouse, &f);
	// mlx_key_hook(f.win, handle_keys, &f);
	mlx_loop(f.mlx);
	return (0);
}