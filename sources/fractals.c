/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:45:45 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/21 19:25:00 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
Calculates the number of iterations for the Mandelbrot set formula at
a given point in the complex plane.
Formula: z = z^2 + c, where z is a complex number and c is the initial point.
Procedure:
1.Initialize zr and zi to 0.
2.Loop until the MAX_ITER count is reached or the magnitude of z exceeds 4.
3.Update zr and zi using the formula z = z^2 + c.
@param cr The real part of the initial complex number.
@param ci The imaginary part of the initial complex number.
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

/*
Calculates the number of iterations at a given point in the complex plane.
Formula: z = z^2 + c, where z is a complex number and c is a constant
defined by the fractal.
Procedure:
1.Initialize zr and zi to the coordinates of the point in the complex plane.
2.Loop until the MAX_ITER count is reached or the magnitude of z exceeds 4.
3.Update zr and zi using the formula z = z^2 + c, where c is the constant
defined by the fractal.
4.Return the number of iterations before the escape condition is met.
@param fractal Pointer to the fractal struct containing the fractal constants.
@param zr The real part of the initial complex number.
@param zi The imaginary part of the initial complex number.
*/
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

/*
Calculates the number of iterations at a given point in the complex plane.
Formula: z = z^2 + c, where z is a complex number and c is the initial point.
Procedure:
1.Initialize zr and zi to 0.
2.Loop until the MAX_ITER count is reached or the magnitude of z exceeds 4.
3.Update zr and zi using the formula z = z^2 + c, with a twist:
zi is negated in the calculation.
4.Return the number of iterations before the escape condition is met.
@param cr The real part of the initial complex number.
@param ci The imaginary part of the initial complex number.
*/
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
