/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:32:58 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/21 19:05:00 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
Sets the color of a specific pixel in the fractal image calculating the offset
within the image buffer based on the number of iterations. The iterations
represent how many times the fractal function was applied before the point
escaped. color_info holds the memory address within the image buffer where the
color information for the current pixel is stored.
*/
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

/*
Calculates the number of iterations for a given point in the complex
plane to determine if it belongs to a specified fractal set
(e.g., Mandelbrot, Julia, Tricorn).
*/
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

/*
Renders a fractal image on the screen by iterating over
each pixel, calculating the corresponding complex plane coordinates,
and determining the color based on the number of iterations needed
to escape the fractal set.
 */
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
