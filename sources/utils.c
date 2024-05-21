/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:56:55 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/21 20:02:26 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
Cleans up resources and exits the program with the specified exit code.
-Destroys the image and window if they exist.
-Ends the MLX event loop and destroys the MLX display.
-Frees memory allocated for the MLX connection.
Exits the program with the specified exit code.
*/
void	clean_exit(int exit_code, t_fractal *fractal)
{
	if (!fractal->mlx)
		exit (exit_code);
	if (fractal->img.img_ptr)
		mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
	if (fractal->wndw && fractal->mlx)
		mlx_destroy_window(fractal->mlx, fractal->wndw);
	if (fractal->mlx)
	{
		mlx_loop_end(fractal->mlx);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
	}
	exit (exit_code);
}

/*
Prints an error or information message to stderr.
-Formats and prints the message to stderr.
Returns the specified error code.
*/
int	msg(char *str1, char *str2, int error)
{
	ft_putstr_fd("Fractol: ", 2);
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
	return (error);
}

/*
Exits the Fractol program cleanly.
Cleans up resources and exits with exit code 0.
*/
int	end_fractol(t_fractal *fractal)
{
	clean_exit(0, fractal);
	return (0);
}
