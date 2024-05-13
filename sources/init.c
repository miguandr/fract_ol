/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:18:14 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/13 20:55:11 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_zero(t_fractal *fractal)
{
	fractal->mlx = NULL;
	fractal->wndw = NULL;
	fractal->img.img_ptr = NULL;
	fractal->img.pixel = NULL;
	fractal->nr = 0;
	fractal->ni = 0;
	fractal->max_r = 0;
	fractal->min_r = 0;
	fractal->max_i = 0;
	fractal->min_i = 0;
	fractal->set = -1;
	fractal->color = 0xfcbe11;
	fractal->img.bitspp = 0;
	fractal->img.line_len = 0;
	fractal->img.endian = 0;
}


void	get_layout(t_fractal *fractal)
{
	if (fractal->set == MANDELBROT)
	{
		fractal->min_r = -2.0;
		fractal->max_r = 1.0;
		fractal->min_i = -1.5;
		fractal->max_i = fractal->min_i + (fractal->max_r - fractal->min_r)
			* (HEIGHT / WIDTH);
	}

	else if (fractal->set == JULIA)
	{
		fractal->min_r = -2.0;
		fractal->max_r = 2.0;
		fractal->max_i = -2.0;
		fractal->min_i = fractal->max_i - (fractal->max_r - fractal->min_r)
			* HEIGHT / WIDTH;
	}
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		clean_exit(msg("Failed connecting to MLX.", "", 1), fractal);
	fractal->wndw = mlx_new_window(fractal->mlx, HEIGHT, WIDTH, "Fractol");
	if (!fractal->wndw)
		clean_exit(msg("Failed creating window.", "", 1), fractal);
	get_layout(fractal);

	fractal->img.img_ptr = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img.img_ptr)
		clean_exit(msg("Failed creating image.", "", 1), fractal);
	fractal->img.pixel = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bitspp, &fractal->img.line_len, &fractal->img.endian);

	//events_init(fractal);//TODO
	//data_init(fractal);//TODO
}

