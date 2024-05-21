/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:18:14 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/21 19:42:22 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
Initializes the fields of the fractal structure to default zero values.
Sets default values for colors and initial zoom level.
Ensures all pointers are set to NULL to avoid unintended behavior.
*/
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
	fractal->center_r = 0.0;
	fractal->center_i = 0.0;
	fractal->viewport_width = 0.0;
	fractal->viewport_height = 0.0;
	fractal->set = 0;
	fractal->color_main = 0x0000000;
	fractal->color = 0xfcbe11;
	fractal->color_set = 1;
	fractal->img.bitspp = 0;
	fractal->img.line_len = 0;
	fractal->img.endian = 0;
}

/*
Sets up the layout for the fractal view based on the selected fractal set.
Configures the center and viewport dimensions for the different fractals.
Calculates the minimum and maximum real and imaginary values for the
fractal view.
*/
void	get_layout(t_fractal *fractal)
{
	if (fractal->set == MANDELBROT)
	{
		fractal->center_r = -0.5;
		fractal->center_i = 0.0;
		fractal->viewport_width = 3.0;
	}
	else if (fractal->set == JULIA || fractal->set == TRICORN)
	{
		fractal->center_r = 0.0;
		fractal->center_i = 0.0;
		fractal->viewport_width = 4.0;
	}
	fractal->viewport_height = fractal->viewport_width;
	fractal->min_r = fractal->center_r - fractal->viewport_width / 2.0;
	fractal->max_r = fractal->center_r + fractal->viewport_width / 2.0;
	fractal->min_i = fractal->center_i - fractal->viewport_height / 2.0;
	fractal->max_i = fractal->center_i + fractal->viewport_height / 2.0;
}

/*
Initializes the fractal environment by setting up the MLX connection and window.
- Connects to the MLX library.
- Creates a new window.
- Sets the fractal layout.
- Creates a new image and retrieves its data address.
Handles errors by cleaning up and exiting if any initialization step fails.
 */
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
}
