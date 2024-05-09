/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:18:14 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/09 18:46:08 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	malloc_error(void)
{
	write(2, "MALLOC ERROR\n", 13);
	exit (EXIT_FAILURE);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->cnx = mlx_init();
	if (fractal->cnx == NULL)
		malloc_error();
	fractal->wndw = mlx_new_window(fractal->cnx, HEI, WID, fractal->name);
	if (fractal->wndw == NULL)
	{
		mlx_destroy_display(fractal->cnx);
		free(fractal->cnx);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->cnx, WID, HEI);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->cnx, fractal->wndw);
		mlx_destroy_display(fractal->cnx);
		free(fractal->cnx);
		malloc_error();
	}
	fractal->img.pixel = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bitspp, &fractal->img.line_len, &fractal->img.endian);
	//events_init(fractal);//TODO
	//data_init(fractal);//TODO
}

