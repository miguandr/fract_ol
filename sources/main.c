/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:27:27 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/20 09:24:08 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

static void	handle_args(t_fractal *fractal, int ac, char **av)
{
	get_set(fractal, av);
	if (fractal->set != JULIA && ac > 3)
		info_msg(fractal);
	else if (fractal->set == JULIA && ac > 5)
		info_msg(fractal);
	get_julia_values(fractal, ac, av);
}

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
