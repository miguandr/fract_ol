/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:53:37 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/20 00:20:51 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	change_fractal(t_fractal *fractal)
{
	fractal->set++;
	if (fractal->set == 1)
		get_layout(fractal);
	else if (fractal->set == 2)
		get_layout(fractal);
	else if (fractal->set == 3)
		get_layout(fractal);
	if (fractal->set > 3)
		fractal->set = 1;
}

void	change_color(t_fractal *fractal)
{
	fractal->color_set++;
	if (fractal->color_set == 2)
	{
		fractal->color = 0x001FE8;
		fractal->color_main = 0xffffaa;
	}
	else if (fractal->color_set == 3)
	{
		fractal->color = 0xFFF53D;
		fractal->color_main = 0x05014a;
	}
	else if (fractal->color_set == 4)
	{
		fractal->color = 0xE6E6FA;
		fractal->color_main = 0xffffff;
	}
	if (fractal->color_set > 4)
	{
		fractal->color_set = 1;
		fractal->color = 0xfcbe11;
		fractal->color_main = 0x0000000;
	}
}

void	zoom(t_fractal *fractal, double zoom)
{
	double	center_r;
	double	center_i;

	center_r = fractal->min_r - fractal->max_r;
	center_i = fractal->max_i - fractal->min_i;
	fractal->max_r = fractal->max_r + (center_r - zoom * center_r) / 2;
	fractal->min_r = fractal->max_r + zoom * center_r;
	fractal->min_i = fractal->min_i + (center_i - zoom * center_i) / 2;
	fractal->max_i = fractal->min_i + zoom * center_i;
}

void	move(t_fractal *fractal, double distance, char direction)
{
	double	center_r;
	double	center_i;

	center_r = (fractal->max_r - fractal->min_r) * distance;
	center_i = (fractal->max_i - fractal->min_i) * distance;
	if (direction == 'L')
	{
		fractal->min_r -= center_r;
		fractal->max_r -= center_r;
	}
	else if (direction == 'R')
	{
		fractal->min_r += center_r;
		fractal->max_r += center_r;
	}
	else if (direction == 'D')
	{
		fractal->min_i -= center_i;
		fractal->max_i -= center_i;
	}
	else if (direction == 'U')
	{
		fractal->min_i += center_i;
		fractal->max_i += center_i;
	}
}
