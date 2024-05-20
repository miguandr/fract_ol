/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:45:45 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/20 09:24:50 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
* r = (x^2 - y^2)
* i = 2 * x * y
* c = complex
* z = variable z
*/
int	mandelbrot(double cr, double ci)
{
	double	zr;
	double	zi;
	double	temp;
	int		iterations;

	zr = 0;
	zi = 0;
	iterations = -1;
	while (++iterations < MAX_ITER)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		temp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = temp;
	}
	return (iterations);
}

int	julia(t_fractal *fractal, double zr, double zi)
{
	double	temp;
	int		iterations;

	iterations = -1;
	while (++iterations < MAX_ITER)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		temp = 2 * zr * zi + fractal->ni;
		zr = zr * zr - zi * zi + fractal->nr;
		zi = temp;
	}
	return (iterations);
}

int	tricorn(double cr, double ci)
{
	double	zr;
	double	zi;
	double	temp;
	int		iterations;

	zr = 0;
	zi = 0;
	iterations = -1;
	while (++iterations < MAX_ITER)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		temp = zr * zr - zi * zi + cr;
		zi = -2 * zr * zi + ci;
		zr = temp;
	}
	return (iterations);
}
