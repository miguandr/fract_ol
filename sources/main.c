/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:27:27 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/09 22:32:54 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_cmp(char *av, char *str)
{
	int	i;

	i = 0;
	while (av[i])
	{
		av[i] = ft_tolower(av[i]);
		i++;
	}
	if (!ft_strncmp(av, str, ft_strlen(str) + 1))
		return (1);
	return (0);
}

void	get_set(t_fractal *fractal, char **av)
{
	if (ft_cmp(av[1], "mandelbrot"))
		fractal->set = MANDELBROT;
	else if (ft_cmp(av[1], "julia"))
		fractal->set = JULIA;
	else if (ft_cmp(av[1], "mandelbox"))
		fractal->set = MANDELBOX; // REMEMBER TO DECIDE WHICH EXTRA FRACTAL
	else
		info_msg(fractal);
}

void	get_julia_values(t_fractal *fractal, int ac, char **av)
{
	if (fractal->set != JULIA || ac == 2)
	{
		fractal->nr = -0.835;
		fractal->ni = -0.2321;
		return ;
	}
	if (ac == 3)
		info_msg(fractal);
	if (!ft_strchr(av[2], '.'))
		info_msg(fractal);
	if (!ft_strchr(av[3], '.'))
		info_msg(fractal);
	fractal->nr = ft_atoi(av[2]);
	fractal->ni = ft_atoi(av[3]);
	if (fractal->nr > 2.0 || fractal->nr < -2.0)
		info_msg(fractal);
	if (fractal->ni > 2.0 || fractal->ni < -2.0)
		info_msg(fractal);
}

void	handle_args(t_fractal *fractal, int ac, char **av)
{
	get_set(fractal, av);
	if (fractal->set != JULIA && ac > 3)
		info_msg(fractal);
	else if (fractal->set == JULIA && ac > 5)
		info_msg(fractal);
	get_julia_values(fractal, ac, av);
	//get_color(); //DO OR DONT?
}

int	main(int ac, char *av[])
{
	t_fractal	fractal;

	if (ac < 2)
		info_msg(&fractal);
	// clean_init(&fractal); //TODO
	handle_args(&fractal, ac, av);
	// fractal_init(&fractal); //TODO
	// fractal_render(&fractal); //TODO
	// print_controls(); //TODO
	// mlx_hook(); //TODO
	// mlx_key_hook(); //TODO
	// mlx_mouse_hook(); _//TODO
	// mlx_loop(); //TODO
	return (0);
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
