/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:53:30 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/20 13:28:42 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT 1250
# define LENGTH 1250
# define MAX_ITERATION 25
# define MANDELBROT 1
# define JULIA 2
# include "./libft/libft.h"
# include  "./minilibx_opengl_20191021/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <math.h>

enum {
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	UP_ARROW = 126,
	DOWN_ARROW = 125,
	LEFT_ARROW = 123,
	RIGHT_ARROW = 124,
	LEFT_CTRL = 256,
	LEFT_ALT = 261,
	LEFT_SHIFT = 257,
	ESC			= 53,
	ON_DESTROY	= 17,
	ON_MOUSE_DW	= 4,
};

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	t;
}	t_color;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_img			*img_data;
	t_color			*color;
	double			min_r;
	double			max_r;
	double			min_i;
	double			max_i;
	unsigned int	count;
	int				color_shift;
	int				resolution_shift;
	int				set;
	double			center_i;
	double			center_r;
	double			julia_shiftx;
	double			julia_shifty;
	char			**args;
}	t_data;

// initialization functions 
t_data	clean_init(void);
void	mlx_setup(t_data *f);
void	command_list(t_data *f);

// Sorting / Parsing functions
void	sort_fractal(t_data *f, char *arg);
int		generate_fractal(t_data *f);
void	set_minmax(t_data *f);

// Mandelbrot functions
int		is_mandelbrot(double cr, double ci, t_data *f);
void	gen_mandelbrot(t_data *f);

// Julia functions
void	gen_julia(t_data	*f);
int		is_julia(double cr, double ci, t_data	*f);
void	julia_shift(int x, int y, t_data *f);

// render and color functions
void	my_px_put(t_img *img, int x, int y, int color);
int		make_color(t_data *f);
int		create_trgb(int t, int r, int g, int b);
void	shift_color(t_data *f);
void	apply_shift(t_data	*f);
int		get_red(int color_value);
int		get_green(int color_value);
int		get_blue(int color_value);

// MISC functions
int		ft_is_little_endian(void);

//	exit functions
void	clean_exit(t_data *f);

// event handling functions:
int		handle_keys(int keycode, t_data *f);
int		handle_mouse(int x, int y, int mousecode, t_data *f);
void	mouse_zoom(t_data *f, double zoom, int x, int y);
void	move(t_data *f, char direction);
void	handle_events(t_data *f);

#endif