/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:27:27 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/09 18:53:28 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int ac, char *av[])
{
	t_fractal	fractal;

	if (ac < 2)
		info_msg(&fractal); //TODO
	clean_init(&fractal); //TODO
	handle_args(&fractal, ac, av); //TODO
	fractal_init(&fractal); //TODO
	fractal_render(&fractal); //TODO
	print_controls(); //TODO
	mlx_hook(); //TODO
	mlx_key_hook(); //TODO
	mlx_mouse_hook(); _//TODO
	mlx_loop(); //TODO
}


/*
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
*/
