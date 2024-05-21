/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:58:35 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/21 19:34:22 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
Handles mouse input events to zoom in and out of the fractal view.
Zooms in when the mouse wheel is scrolled up.
Zooms out when the mouse wheel is scrolled down.
Renders the fractal after processing the input.
*/
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

/*
Handles keyboard input events to interact with the fractal view.
Ends the program when the escape key is pressed.
Zooms in or out using specific keys.
Moves the view left, right, down, or up using arrow keys.
Changes color schemes or fractal sets with specific keys.
Renders the fractal after processing the input.
*/
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

/*
Sets up event handlers for managing window events.
Hooks the window close event to the end_fractol function.
Hooks keyboard input events to the keyboard_input function.
Hooks mouse input events to the mouse_input function.
*/
void	event_management(t_fractal *fractal)
{
	mlx_hook(fractal->wndw, FINISH_EVENT, 0, end_fractol, fractal);
	mlx_key_hook(fractal->wndw, keyboard_input, fractal);
	mlx_mouse_hook(fractal->wndw, mouse_input, fractal);
}
