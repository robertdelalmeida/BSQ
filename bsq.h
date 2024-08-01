/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriede <gabriede@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:25:07 by gabriede          #+#    #+#             */
/*   Updated: 2024/07/31 22:26:31 by gabriede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

struct s_mh
{
	int		line;
	int		collum;
	char	empty;
	char	obstacle;
	char	replace;
};

struct s_pt
{
	int		line_p;
	int		collum_p;
	int		size;
	char	emp_pt;
};

struct s_sq
{
	int	size_sq;
	int	line_sq;
	int	collum_sq;
};

int		ft_search_pts(char **map, struct s_pt *pts, struct s_mh *map_h);
void	ft_create_points2(int size, int sizec, int p, struct s_pt *pts);
void	ft_create_points(int line, int collum, int p, struct s_pt *pts);
void	ft_sort_sqrs(struct s_sq *sqrs, int p);
void	ft_create_sqrs(struct s_sq *sqrs, int size, struct s_pt *pts, int p);
void	ft_sch_sq(char **map, struct s_pt *pts, int p, struct s_sq *sqrs);
void	ft_swap_sqrs(struct s_sq *sqrs, int i);
int		ft_read(char *buffer, struct s_mh *map_h);
void	ft_map(char *buffer, struct s_mh *map_h, int j);
void	ft_algorithm_start(char **map, struct s_mh *map_h);
void	ft_changer(struct s_sq *sqrs, char **map, struct s_mh *map_h);
void	ft_print_map(char **map, struct s_mh *map_h, struct s_sq *sqrs);
int		ft_atoi(char *str);
char	ft_help1(char *buffer);
char	ft_help2(char *buffer);
char	ft_help3(char *buffer);

#endif // BSQ_H