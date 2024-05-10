/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:18:14 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/10 23:01:59 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		clean_exit(msg("Failed connecting to MLX.", "", 1), fractal);
	fractal->wndw = mlx_new_window(fractal->mlx, HEIGHT, WIDTH, "Fractol");
	if (!fractal->wndw)
		clean_exit(msg("Failed creating window.", "", 1), fractal);
	fractal->img.img_ptr = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img.img_ptr)
		clean_exit(msg("Failed creating image.", "", 1), fractal);
	fractal->img.pixel = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bitspp, &fractal->img.line_len, &fractal->img.endian);

	//events_init(fractal);//TODO
	//data_init(fractal);//TODO
}

