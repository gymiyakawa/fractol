/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:03:15 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/07 16:59:09 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

	// bit shifts the ints into the correct position for color coding
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// makes different colors depeding on the number of iterations for each
// point in the grid.

// color shift is an attempt at changing the color live.

int	make_color (int count, int *color_shift)
{
	int t;
	int r;
	int g;
	int b;
	int i;

	t = 0;
	r = 0;
	g = 0;
	b = 0;
	i = -1;git 
	if (*color_shift % 7 == 0)
		{
			r += 150;
			b += 100;
		}
	if (*color_shift % 2 == 0)
		r += 200;
	if (*color_shift % 3 == 0)
		g += 200;
	if (*color_shift % 5 == 0)
		b += 200;
	while (++i <= count * 2)
	{
		if (r <= 250 && g <= 250)
			r += 5;
		else if (g <= 250)
			g += 5;
		else if(r >= 5)
			r -= 5;
		else if (g >= 250 && (b <= 250))
			b += 5;
		else if (g >= 5)
			g -= 5;
	}
	return (create_trgb(t, r, g, b));
}


// function must: increment the value of color_shift, destroy the current image,
// create a new one and push it to the window.

void	shift_color(t_data *f)
{
	f->color_shift += 1;

	gen_mandelbrot(f);
	mlx_key_hook(f->win, key_exit, f);
	mlx_loop(f->mlx);
}



// int	make_color (int count)
// {
// 	int rainbow[7][3] = {0};

// 	rainbow[0][0] = 148;
// 	rainbow[0][2] = 211;
// 	rainbow[1][0] = 75;
// 	rainbow[1][2] = 130;
// 	rainbow[2][2] = 255;
// 	rainbow[3][1] = 255;
// 	rainbow[4][0] = 255;
// 	rainbow[4][1] = 255;
// 	rainbow[5][0] = 255;
// 	rainbow[5][1] = 127;
// 	rainbow[6][0] = 255;

// 	while (count > 7)
// 		count %= 7;
// 	return(create_trgb(0, rainbow[count][0], rainbow[count][1],\
// 						rainbow[count][2]));
// }