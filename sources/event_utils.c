/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:53:37 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/21 19:31:23 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
Advances the fractal set to the next one in the sequence, cycling
back to the first set if the end is reached.
Updates the fractal layout after changing the set.
*/
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

/*
Advances the color scheme to the next one in the sequence, cycling
back to the first scheme if the end is reached.
Sets specific colors based on the current color scheme.
*/
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

/*
Adjusts the zoom level of the fractal, focusing on the center of the current
view. Calculates new boundaries of the fractal view based on the zoom factor.
*/
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

/*
Moves the view of the fractal in the specified direction by a given distance.
Updates the fractal view boundaries based on the direction and distance.
*/
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
