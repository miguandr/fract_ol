/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:27:27 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/06 21:21:11 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int ac, char *av[])
{
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
	{
		//ft_mandelbrot (TO DO)
	}
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 5))
	{
		//ft_julia (TO DO)
	}
	else
	{
		//error_meesage (TO DO)
	}
}
