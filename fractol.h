/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:53:30 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/01 15:22:53 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#define HEIGHT 800
#define LENGTH 800
#define MAX_ITERATION 60
#include "./libft/libft.h"
#include  "./minilibx_opengl_20191021/mlx.h"
#include <stdlib.h>
#include <math.h>


// what are the things I need?
typedef	struct	s_data
{
	void	*mlx;
	void	*img;
	void	*win;
	char	*img_addr;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int 	count;
} t_data;

// initialization functions 
void clean_init(t_data *f);
void mlx_setup(t_data *f);

// Mandelbrot functions
int is_mandelbrot (double cr, double ci, t_data *f);
void	gen_mandelbrot(t_data *f);

// MISC functions
int	ft_is_little_endian();
int draw_line(void *mlx_ptr, void *n_window, int beginX,\
					int beginY, int endX, int endY, int color);


//void	myfree(void *p);

#endif 