/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:23:49 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/10 23:00:49 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	fractal_options(void)
{
	ft_putendl_fd("***** Available Fractals *****\n", 1);
	ft_putendl_fd("\e[1mChoose one fractal:\e[0m", 1);
	ft_putendl_fd("* Mandelbrot *", 1);
	ft_putendl_fd("* Julia *", 1);
	ft_putendl_fd("* Mandelbox *\n", 1); //EDIT IF CHOOSING DIFFEREN
	ft_putendl_fd("\e[43mUsage example:\e[0m\t", 1);
	ft_putendl_fd("./fractol <type>", 1);
	ft_putstr_fd("\nFor Julia, you may specify the starting value.\n", 1);
	ft_putstr_fd("Values must be between -2.0 and 2.0\n", 1);
	ft_putendl_fd("\n\e[43mUsage example:\e[0m\t", 1);
	ft_putendl_fd("./fractol Julia 0.285 0.01\n", 1);
	ft_putendl_fd("\e[4menjoy the trip..\e[0m :)", 1);
}

/*void	color_options(void)
{

}*/

void	info_msg(t_fractal *fractal)
{
	ft_putendl_fd("\n******************************", 1);
	ft_putendl_fd("|          FRACT'OL          |", 1);
	ft_putendl_fd("******************************\n", 1);
	fractal_options();
	//color_options(); TODO
	clean_exit(EXIT_FAILURE, fractal);
}
