/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriede <gabriede@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:41:47 by gabriede          #+#    #+#             */
/*   Updated: 2024/07/31 20:57:55 by gabriede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_swap_sqrs(struct s_sq *sqrs, int i)
{
	int	temp;

	temp = sqrs[i].size_sq;
	sqrs[i].size_sq = sqrs[i + 1].size_sq;
	sqrs[i + 1].size_sq = temp;
	temp = sqrs[i].line_sq;
	sqrs[i].line_sq = sqrs[i + 1].line_sq;
	sqrs[i + 1].line_sq = temp;
	temp = sqrs[i].collum_sq;
	sqrs[i].collum_sq = sqrs[i + 1].collum_sq;
	sqrs[i + 1].collum_sq = temp;
}

void	ft_sort_sqrs(struct s_sq *sqrs, int p)
{
	int	i;
	int	temp_p;

	temp_p = p;
	while (p > 0)
	{
		i = 0;
		while (i < temp_p)
		{
			if (sqrs[i].size_sq <= sqrs[i + 1].size_sq)
			{
				if (sqrs[i].size_sq < sqrs[i + 1].size_sq)
					ft_swap_sqrs(sqrs, i);
				else if (sqrs[i].line_sq > sqrs[i + 1].line_sq)
					ft_swap_sqrs(sqrs, i);
				else if (sqrs[i].collum_sq > sqrs[i + 1].collum_sq)
					ft_swap_sqrs(sqrs, i);
			}
			i++;
		}	
		p--;
	}	
}

void	ft_create_sqrs(struct s_sq *sqrs, int size, struct s_pt *pts, int p)
{
	sqrs[p].line_sq = pts[p].line_p;
	sqrs[p].collum_sq = pts[p].collum_p;
	sqrs[p].size_sq = size;
}

void	ft_sch_sq(char **map, struct s_pt *pts, int p, struct s_sq *sqrs)
{
	int	l;
	int	c;
	int	cl_i;
	int	ln_i;
	int	size_l;

	size_l = pts[p].size + 1;
	while (--size_l > 0)
	{
		l = pts[p].line_p;
		ln_i = size_l;
		cl_i = 0;
		while (ln_i > 0 && cl_i == 0)
		{
			cl_i = size_l + 1;
			c = pts[p].collum_p;
			while ((l >= 0 && l < pts[p].size) && (c >= 0 && c < pts[p].size)
				&& --cl_i > 0 && map[l][c] == pts[0].emp_pt)
				c++;
			l++;
			ln_i--;
			if (cl_i == 0 && ln_i == 0)
				return (ft_create_sqrs(sqrs, size_l, pts, p));
		}
	}
}
