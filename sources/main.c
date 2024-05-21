/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:27:27 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/21 19:51:08 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
Compares a string with a given string or character.
-Converts the argument string to lowercase.
-Compares the argument string with the target string or character.
Returns 1 if the strings match or the character is found,
otherwise, returns 0.
*/
static int	ft_cmp(char *av, char *str, char num)
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
	else if (av[1] == '\0' && av[0] == num)
		return (1);
	return (0);
}

/*
Sets the fractal type based on the command-line arguments.
-Compares the argument with predefined fractal names.
-Sets the fractal type accordingly.
Prints an information message if the argument is not recognized.
*/
void	get_set(t_fractal *fractal, char **av)
{
	if (ft_cmp(av[1], "mandelbrot", 1))
		fractal->set = MANDELBROT;
	else if (ft_cmp(av[1], "julia", 2))
		fractal->set = JULIA;
	else if (ft_cmp(av[1], "tricorn", 3))
		fractal->set = TRICORN;
	else
		info_msg(fractal);
}

/*
Retrieves and validates Julia set parameters from command-line arguments.
-Sets default values if the fractal is not Julia or if arguments are missing.
-Retrieves real and imaginary values from command-line arguments.
-Validates the values and prints an information message if they are invalid.
*/
static void	get_julia_values(t_fractal *fractal, int ac, char **av)
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
	fractal->nr = ft_atof(av[2]);
	fractal->ni = ft_atof(av[3]);
	if (fractal->nr > 2.0 || fractal->nr < -2.0)
		info_msg(fractal);
	if (fractal->ni > 2.0 || fractal->ni < -2.0)
		info_msg(fractal);
}

/**
Handles command-line arguments to set up the fractal environment.
-Sets the fractal type based on the first argument.
-Validates and retrieves Julia set parameters if applicable.
Prints an information message if arguments are invalid.
*/
static void	handle_args(t_fractal *fractal, int ac, char **av)
{
	get_set(fractal, av);
	if (fractal->set != JULIA && ac > 3)
		info_msg(fractal);
	else if (fractal->set == JULIA && ac > 5)
		info_msg(fractal);
	get_julia_values(fractal, ac, av);
}

/*
Entry point of the program.
-Validates the number of command-line arguments.
-Initializes the fractal structure with default values.
-Handles command-line arguments to set up the fractal environment.
-Initializes the fractal environment.
-Renders the fractal.
-Prints control information.
-Sets up event management for fractal interaction.
Enters the MLX event loop to handle events.
*/
int	main(int ac, char *av[])
{
	t_fractal	fractal;

	if (ac < 2)
		info_msg(&fractal);
	init_zero(&fractal);
	handle_args(&fractal, ac, av);
	fractal_init(&fractal);
	fractal_render(&fractal);
	print_controls();
	event_management(&fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
