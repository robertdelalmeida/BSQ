/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_points.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriede <gabriede@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:31:05 by gabriede          #+#    #+#             */
/*   Updated: 2024/07/31 20:56:03 by gabriede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_create_points2(int size, int sizec, int p, struct s_pt *pts)
{	
	if (size >= sizec)
		pts[p].size = sizec;
	else if (size < sizec)
		pts[p].size = size;
}

void	ft_create_points(int line, int collum, int p, struct s_pt *pts)
{	
	pts[p].line_p = line;
	pts[p].collum_p = collum;
}

int	ft_search_pts(char **map, struct s_pt *pts, struct s_mh *map_h)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	pts[0].emp_pt = map_h[0].empty;
	while (i < map_h[0].line)
	{
		j = 0;
		while (j < map_h[0].collum)
		{
			if (map[i][j] == pts[0].emp_pt)
			{
				ft_create_points(i, j, p, pts);
				ft_create_points2(map_h[0].line, map_h[0].collum, p, pts);
				p++;
			}
			j++;
		}
		i++;
	}
	return (p);
}
