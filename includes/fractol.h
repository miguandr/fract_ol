/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:25:17 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/13 21:18:39 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"

/*-Dimensions-*/
# define HEIGHT 800
# define WIDTH 800
# define MAX_ITER 50

/*-Fractal sets-*/
# define MANDELBROT 1
# define JULIA 2
# define MANDELBOX 3

/*-Image Struct- (values from mxl_get_data_addr)*/
//-Image buffer
typedef struct s_image
{
	void	*img_ptr; //pointer to image struct
	char	*pixel; //points to the actual pixels
	int		bitspp;
	int		line_len;
	int		endian;
}				t_image;

/*-Fractal Struct-*/
//-mxl data
//-image
//-hooks values
typedef struct s_fractal
{
	int		set;
	int		color;
	void	*mlx;
	void	*wndw;
	double	nr;
	double	ni;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;

	t_image	img; //buffer

	//hooks member variables //TODO
}				t_fractal;

/*-Fractals-*/
int		mandelbrot(double cr, double ci);
int		julia(t_fractal *fractal, double zr, double zi);

/*-Render-*/
void	fractal_render(t_fractal *fractal);
void	my_put_pixel(t_image *img, int x, int y, int color);

/*-Utils-*/
void	info_msg(t_fractal *fractal);
void	clean_exit(int exit_code, t_fractal *fractal);
int		end_fractol(t_fractal *mlx);
int		msg(char *str1, char *str2, int error);

/*-Init Functions-*/
void	init_zero(t_fractal *fractal);
void	fractal_init(t_fractal *fractal);

#endif
