/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:08:03 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/20 15:09:45 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
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

	   man locations: /usr/share/man/man3/
 */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_data	f;

	if (ac < 2 || !av[1])
	{
		ft_printf("error: missing argument.\n");
		return (-1);
	}
	f = clean_init();
	set_minmax(&f);
	f.args = av;
	sort_fractal(&f, av[1]);
	mlx_setup(&f);
	command_list(&f);
	mlx_loop_hook(f.mlx, &generate_fractal, &f);
	mlx_loop(f.mlx);
	return (0);
}
