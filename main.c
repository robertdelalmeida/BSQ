/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriede <gabriede@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:50:31 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/07/31 22:34:59 by gabriede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char *argv[])
{
	struct s_mh	*map_h;
	char		*buffer;
	int			fd;
	int			i;
	int			j;

	i = 1;
	map_h = malloc(3200);
	while (argc > 1)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			buffer = argv[i];
		else
		{
			buffer = malloc(3200);
			read(fd, buffer, 3199);
			buffer[3200] = 0;
		}
		j = ft_read(buffer, map_h);
		ft_map(buffer, map_h, j);
		write(1, "\n", 1);
		argc--;
		i++;
	}
}

int	ft_read(char *buffer, struct s_mh *map_h)
{
	int	i;
	int	j;

	map_h[0].line = ft_atoi(buffer);
	map_h[0].empty = ft_help1(buffer);
	map_h[0].obstacle = ft_help2(buffer);
	map_h[0].replace = ft_help3(buffer);
	i = 0;
	while (buffer[i] != '\n')
		i++;
	j = i + 1;
	while (buffer[j] != '\n')
		j++;
	map_h[0].collum = j - (i + 1);
	return (i);
}

void	ft_map(char *buffer, struct s_mh *map_h, int j)
{
	char	**map;
	int		num_line;
	int		i;
	int		num_collum;

	i = -1;
	map = malloc(map_h[0].line * sizeof(char *));
	while (++i < map_h[0].line)
		map[i] = malloc(map_h[0].collum + 1 * sizeof(char));
	i = j;
	num_line = 0;
	while (num_line < map_h[0].line)
	{
		num_collum = 0;
		while (buffer[++i] != '\n')
		{
			map[num_line][num_collum] = buffer[i];
			num_collum++;
		}
		map[num_line][num_collum] = '\n';
		num_line++;
	}
	ft_algorithm_start(map, map_h);
}

int	ft_atoi(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}
