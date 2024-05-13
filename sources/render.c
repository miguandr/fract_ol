/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:32:58 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/13 22:15:56 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	calculate_fractal(t_fractal *fractal, double pr, double pi)
{
	int	iterations;

	iterations = 0;
	if (fractal->set == MANDELBROT)
		iterations = mandelbrot(pr, pi);
	else if (fractal->set == JULIA)
		iterations = julia(fractal, pr, pi);
	return (iterations);
}

void	fractal_render(t_fractal *fractal)
{
	int		x;
	int		y;
	int		iterations;
	double	pr;
	double	pi;

	//mlx_clear_window();
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
			fractal->img.pixel = mlx_get_data_addr(fractal->img.img_ptr,
					&fractal->img.bitspp, &fractal->img.line_len,
					&fractal->img.endian);
	//		my_put_pixel(&fractal->img, x, y, fractal->color);
		}
	//	mlx_put_image_to_window(fractal->mlx, fractal->wndw,
	//		fractal->img.img_ptr, x, y);
	}
}

void	my_put_pixel(t_image *img, int x, int y, int color)
{
	char	*color_info;

	color_info = img->pixel + (y * img->line_len + x * (img->bitspp / 8));
	*(unsigned int *)color_info = color;
}

/*
*https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#compilation-on-macos
*https://qst0.github.io/ft_libgfx/man_mlx_pixel_put.html
*http://warp.povusers.org/Mandelbrot/
*https://medium.com/@leogaudin/fract-ol-creating-graphically-beautiful-fractals-6664b6b045b5
*https://gontjarow.github.io/MiniLibX/mlx-tutorial-create-image.html?source=post_page-----6664b6b045b5--------------------------------
*/
