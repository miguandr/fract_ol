/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:58:35 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/20 00:26:01 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	mouse_input(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == MOUSE_W_UP)
		zoom(fractal, 0.8);
	else if (button == MOUSE_W_DOWN)
		zoom(fractal, 2);
	else
		return (1);
	fractal_render(fractal);
	return (0);
}

static int	keyboard_input(int keycode, t_fractal *fractal)
{
	if (keycode == KEY_ESC)
	{
		end_fractol(fractal);
		return (0);
	}
	else if (keycode == ZOOM_IN)
		zoom(fractal, 0.8);
	else if (keycode == ZOOM_OUT)
		zoom(fractal, 2);
	else if (keycode == KEY_LEFT)
		move(fractal, 0.2, 'L');
	else if (keycode == KEY_RIGHT)
		move(fractal, 0.2, 'R');
	else if (keycode == KEY_DOWN)
		move(fractal, 0.2, 'D');
	else if (keycode == KEY_UP)
		move(fractal, 0.2, 'U');
	else if (keycode == COLOR)
		change_color(fractal);
	else if (keycode == FRACTAL_SET)
		change_fractal(fractal);
	else
		return (1);
	fractal_render(fractal);
	return (0);
}

void	event_management(t_fractal *fractal)
{
	mlx_hook(fractal->wndw, FINISH_EVENT, 0, end_fractol, fractal);
	mlx_key_hook(fractal->wndw, keyboard_input, fractal);
	mlx_mouse_hook(fractal->wndw, mouse_input, fractal);
}
