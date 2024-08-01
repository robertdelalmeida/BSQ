/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriede <gabriede@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:47:51 by gabriede          #+#    #+#             */
/*   Updated: 2024/07/31 22:34:35 by gabriede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	ft_help1(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] >= '0' && buffer[i] <= '9')
		i++;
	return (buffer[i]);
}

char	ft_help2(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] >= '0' && buffer[i] <= '9')
		i++;
	return (buffer[i + 1]);
}

char	ft_help3(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] >= '0' && buffer[i] <= '9')
		i++;
	return (buffer[i + 2]);
}
