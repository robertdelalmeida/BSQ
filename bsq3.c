/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriede <gabriede@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:05:03 by gabriede          #+#    #+#             */
/*   Updated: 2024/07/31 21:28:45 by gabriede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_print_map(char **map, struct s_mh *map_h, struct s_sq *sqrs)
{
	int	i;
	int	j;

	if (sqrs[0].size_sq < 2)
	{
		write(1, "map error", 9);
		return ;
	}
	i = 0;
	while (i < map_h[0].line)
	{
		j = 0;
		while (j < map_h[0].collum)
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_changer(struct s_sq *sqrs, char **map, struct s_mh *map_h)
{
	int	line_start;
	int	cl_start;
	int	i_cl;
	int	i_line;

	line_start = sqrs[0].line_sq;
	i_line = 0;
	while (i_line < sqrs[0].size_sq)
	{
		i_cl = 0;
		cl_start = sqrs[0].collum_sq;
		while (i_cl < sqrs[0].size_sq)
		{
			map[line_start][cl_start] = map_h[0].replace;
			cl_start++;
			i_cl++;
		}
		line_start++;
		i_line++;
	}
}

void	ft_algorithm_start(char **map, struct s_mh *map_h)
{
	struct s_sq	*sqrs;
	struct s_pt	*pts;
	int			p;
	int			k;

	pts = malloc((map_h[0].line * map_h[0].collum * 10) * sizeof(struct s_pt));
	p = ft_search_pts(map, pts, map_h);
	sqrs = malloc((p * 4) * sizeof(struct s_sq));
	k = 0;
	while (k <= p)
	{
		ft_sch_sq(map, pts, k, sqrs);
		k++;
	}
	free(pts);
	k = 0;
	while (k < p)
	{
		ft_sort_sqrs(sqrs, k);
		k++;
	}
	ft_changer(sqrs, map, map_h);
	ft_print_map(map, map_h, sqrs);
	free(sqrs);
	return ;
}
