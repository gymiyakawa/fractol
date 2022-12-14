/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:22:34 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/14 16:42:37 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// checks for the correct argument and sets f->set accordinly. 


void	sort_fractal(t_data *f, char *arg)
{
	arg = ft_str_tolower(arg);
	if (ft_strcmp(arg, "mandelbrot") == 0)
	{
		f->set = MANDELBROT;
		set_minmax(f);
	}
	else if (ft_strcmp(arg, "julia") == 0)
		f->set = JULIA;
	else
		{
			ft_printf("Error: no such fractal\n");
			ft_printf("Available fractals: Mandelbrot, Julia\n");
			clean_exit(f);
		}
}
*
// generates a fractal based on the value of f->set

int	generate_fractal(t_data *f)
{
	// printf("leaves handle keys = %p \n", f);
	mlx_hook(f->win, 4, 0, handle_mouse, f);
	mlx_key_hook(f->win, handle_keys, f);
	if (f->set == MANDELBROT)
		gen_mandelbrot(f);
	if (f->set	== JULIA)
		gen_julia(f);
	return (0);
}

// sets the correct offset for each fractal. JULIA is currently empty.

void set_minmax (t_data *f)
{
	if (f->set == MANDELBROT)
	{
		f->min_r = - 2.0;
		f->max_r = 2;
		f->max_i = - 2;
		f->min_i = 2;
	}
	if (f->set == JULIA)
		return;
	return;
}
