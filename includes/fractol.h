/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:25:17 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/07 21:16:49 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../mlx_linux/mlx.h"

# define R "Valid input:\n./fractol mandelbrot\n./fractol julia <arg1> <arg2>\n"
# define HEI 800
# define WID 800

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
	char	*name;
	void	*cnx;
	void	*wndw;
	t_image	img; //buffer

	//hooks member variables //TODO
}				t_fractal;


/*-Utils-*/
int		ft_strncmp(char *s1, char *s2, int n);
void	ft_putstr_fd(char *str, int fd);

/*-Init Functions-*/
void	fractal_init(t_fractal *fractal);

#endif
