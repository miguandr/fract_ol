/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:56:55 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/10 23:05:07 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	clean_exit(int exit_code, t_fractal *fractal)
{
	if (!fractal)
		exit (exit_code);
	if (fractal->wndw && fractal->mlx)
		mlx_destroy_window(fractal->mlx, fractal->wndw);
	//IMAGE AND PALETTE?
	if (fractal->mlx)
	{
		mlx_loop_end(fractal->mlx);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
	}
	exit (exit_code);
}

int	msg(char *str1, char *str2, int error)
{
	ft_putstr_fd("Fractol: ", 2);
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
	return (error);
}
