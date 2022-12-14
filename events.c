/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:29:30 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/14 13:18:42 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// a collection of all even handling functions.

#include "fractol.h"

// function to handle mouse inputs. ie zoom
// mouse = scroll up = 4, scroll down = 5 
// left click = 1, right click = 2

int handle_mouse (int mousecode, int x, int y, t_data *f)
{
	(void)x;
	(void)y;
	if (mousecode == 4)
		mouse_zoom(f, 0.9, x, y);
	if (mousecode == 5)
		mouse_zoom(f, 1.1, x, y);
	return (0);
}

// handles keyboard inputs.
// clean exits on pressing ESC, moves with WASD and arrow keys,
// shifts colors with shift, shifts resolutions with alt

int handle_keys (int keycode, t_data *f)
{
	// printf("%d\n", keycode);
	if (keycode == 53)
		clean_exit(f);
	if (keycode == 257)
		shift_color(f);
	if (keycode == UP_ARROW || keycode == W)
		move(f, 'U');
	if (keycode == DOWN_ARROW || keycode == S)
		move(f, 'D');
	if (keycode == LEFT_ARROW || keycode == A)
		move(f, 'L');
	if (keycode == RIGHT_ARROW || keycode == D)
		move(f, 'R');
	if (keycode == LEFT_ALT)
		{
			f->resolution_shift += 100;
			if (f->resolution_shift > 300)
				f->resolution_shift = 0;
			printf("Max iterations: %d\n", (f->resolution_shift + MAX_ITERATION));
		}
	return (0);
}
