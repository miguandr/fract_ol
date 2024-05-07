/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:56:55 by miguandr          #+#    #+#             */
/*   Updated: 2024/05/07 11:26:01 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	if (!s1 || !s2 || n <= 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] && (n > 0))
	{
		i++;
		n--;
	}
	return (s1[i] - s2[i]);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (str == NULL || fd < 0)
		return ;
	while (str[i])
	{
		write(fd,&str[i], 1);
		i++;
	}
}
