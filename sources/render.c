/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:32:58 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/20 09:24:04 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	my_put_pixel(t_fractal *fractal, int x, int y, int iterations)
{
	char	*color_info;


	color_info = fractal->img.pixel + (y * fractal->img.line_len)
		+ (x * (fractal->img.bitspp / 8));

	if (iterations == MAX_ITER)
		*(unsigned int *)color_info = fractal->color_main;
	else
		*(unsigned int *)color_info = fractal->color * iterations;
}

static int	calculate_fractal(t_fractal *fractal, double pr, double pi)
{
	int	iterations;

	iterations = 0;
	if (fractal->set == MANDELBROT)
		iterations = mandelbrot(pr, pi);
	else if (fractal->set == JULIA)
		iterations = julia(fractal, pr, pi);
	else if (fractal->set == TRICORN)
		iterations = tricorn(pr, pi);
	return (iterations);
}

void	fractal_render(t_fractal *fractal)
{
	int		x;
	int		y;
	int		iterations;
	double	pr;
	double	pi;

	mlx_clear_window(fractal->mlx, fractal->wndw);
	iterations = 0;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = fractal->min_r + (double)x
				* (fractal->max_r - fractal->min_r) / WIDTH;
			pi = fractal->max_i - (double)y
				* (fractal->max_i - fractal->min_i) / HEIGHT;
			iterations = calculate_fractal(fractal, pr, pi);
			my_put_pixel(fractal, x, y, iterations);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->wndw,
		fractal->img.img_ptr, 0, 0);
}
