/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:25:17 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/21 20:07:16 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include "keys.h"
# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"

/*-Dimensions-*/
# define HEIGHT 800
# define WIDTH 800
# define MAX_ITER 400

/*-Fractal sets-*/
# define MANDELBROT 1
# define JULIA 2
# define TRICORN 3

/*-Image Struct-*/
typedef struct s_image
{
	void	*img_ptr;
	char	*pixel;
	int		bitspp;
	int		line_len;
	int		endian;
}				t_image;

/*-Fractal Struct-*/
typedef struct s_fractal
{
	int		set;
	int		color;
	int		color_set;
	int		color_main;
	void	*mlx;
	void	*wndw;
	double	nr;
	double	ni;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	center_r;
	double	center_i;
	double	viewport_width;
	double	viewport_height;
	t_image	img;
}				t_fractal;

/*-Fractals-*/
int		mandelbrot(double cr, double ci);
int		julia(t_fractal *fractal, double zr, double zi);
int		tricorn(double cr, double ci);

/*-Utils-*/
void	info_msg(t_fractal *fractal);
void	print_controls(void);
void	clean_exit(int exit_code, t_fractal *fractal);
int		end_fractol(t_fractal *mlx);
int		msg(char *str1, char *str2, int error);

/*-Init Functions-*/
void	init_zero(t_fractal *fractal);
void	fractal_init(t_fractal *fractal);

/*-Render-*/
void	fractal_render(t_fractal *fractal);
void	get_layout(t_fractal *fractal);

/*-Events-*/
void	event_management(t_fractal *fractal);
void	move(t_fractal *fractal, double distance, char direction);
void	zoom(t_fractal *fractal, double zoom);
void	change_color(t_fractal *fractal);
void	change_fractal(t_fractal *fractal);

#endif
