/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:23:49 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/20 09:24:43 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	fractal_options(void)
{
	ft_putendl_fd("***** Available Fractals *****\n", 1);
	ft_putendl_fd("\e[1mChoose one fractal:\e[0m", 1);
	ft_putendl_fd("* Mandelbrot *", 1);
	ft_putendl_fd("* Julia *", 1);
	ft_putendl_fd("* Tricorn *\n", 1);
	ft_putendl_fd("\e[43mUsage example:\e[0m\t", 1);
	ft_putendl_fd("./fractol mandelbrot", 1);
	ft_putstr_fd("\nFor Julia, you may specify the starting value.\n", 1);
	ft_putstr_fd("Values must be between -2.0 and 2.0\n", 1);
	ft_putendl_fd("\n\e[43mUsage example:\e[0m\t", 1);
	ft_putendl_fd("./fractol Julia 0.285 0.01\n", 1);
}

void	print_controls(void)
{
	ft_putendl_fd("\n********** Controls **********\n", 1);
	ft_putendl_fd("Press arrow keys to change the view", 1);
	ft_putendl_fd("Press + or - or scroll the wheel to zoom in/out", 1);
	ft_putendl_fd("Press 'c' to change the color", 1);
	ft_putendl_fd("Press spacebar to change the fractal", 1);
	ft_putendl_fd("Press ESC or close the window to quit Fractol", 1);
	ft_putendl_fd("\n******************************", 1);
	ft_putendl_fd("\n\e[4menjoy the trip..\e[0m :)", 1);
}

void	info_msg(t_fractal *fractal)
{
	ft_putendl_fd("\n******************************", 1);
	ft_putendl_fd("|          FRACT'OL          |", 1);
	ft_putendl_fd("******************************\n", 1);
	fractal_options();
	print_controls();
	clean_exit(EXIT_FAILURE, fractal);
}
