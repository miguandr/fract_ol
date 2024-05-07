/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:27:27 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/07 21:28:16 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int ac, char *av[])
{
	t_fractal	fractal;

	if ((ac == 2 && (!ft_strncmp(av[1], "mandelbrot", 10)))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.name = av[1];
		fractal_init(&fractal);
		//fractal_render(&fractal);//TODO
		//mlx_loop(fractal.cnx);//TODO
	}
	else
	{
		ft_putstr_fd(R, STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
}
