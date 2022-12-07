/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:53:30 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/07 16:25:38 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#define HEIGHT 1500
#define LENGTH 1500
#define MAX_ITERATION 60
#define MLX_ERROR 1
#include "./libft/libft.h"
#include  "./minilibx_opengl_20191021/mlx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <math.h>


typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
} t_img;

typedef	struct	s_data
{
	void	*mlx;
	void	*win;
	t_img	*img_data;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	unsigned int 	count;
	int		color_shift;
} t_data;


// initialization functions 
void clean_init(t_data *f);
void mlx_setup(t_data *f);

// Mandelbrot functions
int is_mandelbrot (double cr, double ci, t_data *f);
void	gen_mandelbrot(t_data *f);

// render and color functions
void	my_px_put(t_img *img, int x, int y, int color);
int	make_color (int count, int *color_shift);
int	create_trgb(int t, int r, int g, int b);
void	shift_color(t_data *f);

// MISC functions
int	ft_is_little_endian();
int draw_line(void *mlx_ptr, void *n_window, int beginX,\
					int beginY, int endX, int endY, int color);

//void	myfree(void *p);
int key_exit (int keycode, t_data *f);
void clean_exit (t_data *f);

#endif 