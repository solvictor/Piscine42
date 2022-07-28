/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:37:56 by vegret            #+#    #+#             */
/*   Updated: 2022/07/27 20:56:15 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_map
{
	char	**terrain;
	int		lines;
	int		columns;
	char	*symbols;
}	t_map;

typedef struct s_point
{
	int	value;
	int	x;
	int	y;
}	t_point;

t_map	*create_map(char **terrain, int lines, int columns, char *symbols);
int		is_valid_map(t_map *map);
void	solve_map(t_map *map);
void	print_map(t_map *map);
void	free_map(t_map *map);
void	handle_map(t_map *map);

#endif