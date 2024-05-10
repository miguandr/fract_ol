/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:25:17 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/10 23:03:07 by miguandr         ###   ########.fr       */
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
	char	set;
	void	*mlx;
	void	*wndw;
	double	nr;
	double	ni;
	t_image	img; //buffer

	//hooks member variables //TODO
}				t_fractal;

/*-Utils-*/
void	info_msg(t_fractal *fractal);
void	clean_exit(int exit_code, t_fractal *fractal);
int		msg(char *str1, char *str2, int error);

/*-Init Functions-*/
void	fractal_init(t_fractal *fractal);



#endif
