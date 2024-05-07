/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:27:27 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/07 14:06:16 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int ac, char *av[])
{
	if ((ac == 2 && (!ft_strncmp(av[1], "mandelbrot", 10)))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{

	}
	else
	{
		ft_putstr_fd(R, STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
}
