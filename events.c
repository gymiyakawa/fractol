/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:29:30 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/20 14:56:35 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// a collection of all even handling functions.

#include "fractol.h"

// function to handle mouse inputs. ie zoom
// mouse = scroll up = 4, scroll down = 5 
// left click = 1, right click = 2

int	handle_mouse(int mousecode, int x, int y, t_data *f)
{
	(void)x;
	(void)y;
	if (mousecode == 4)
		mouse_zoom(f, 0.9, x, y);
	if (mousecode == 5)
		mouse_zoom(f, 1.1, x, y);
	if (mousecode == 2 && f->set == JULIA)
		julia_shift (x, y, f);
	return (0);
}

// handles keyboard inputs.
// clean exits on pressing ESC, moves with WASD and arrow keys,
// shifts colors with shift, shifts resolutions with alt

int	handle_keys(int keycode, t_data *f)
{
	if (keycode == ESC)
		clean_exit(f);
	if (keycode == LEFT_SHIFT)
		shift_color(f);
	if (keycode == W || keycode == UP_ARROW)
		move(f, 'U');
	if (keycode == S || keycode == DOWN_ARROW)
		move(f, 'D');
	if (keycode == A || keycode == LEFT_ARROW)
		move(f, 'L');
	if (keycode == D || keycode == RIGHT_ARROW)
		move(f, 'R');
	if (keycode == LEFT_ALT)
	{
		f->resolution_shift += 50;
		if (f->resolution_shift > 200)
			f->resolution_shift = 0;
		ft_printf("Max iterations: %d\n", (f->resolution_shift + MAX_ITERATION));
	}
	return (0);
}

void	handle_events(t_data *f)
{
	mlx_hook(f->win, ON_MOUSE_DW, 0, handle_mouse, f);
	mlx_key_hook(f->win, handle_keys, f);
	mlx_hook(f->win, ON_DESTROY, 0, (void *)clean_exit, f);
	return ;
}
