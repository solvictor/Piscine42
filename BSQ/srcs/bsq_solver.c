/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:40:09 by pbosc             #+#    #+#             */
/*   Updated: 2022/07/27 22:10:32 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "map.h"
#include "ft.h"
#include "input.h"

int	**mathify(t_map *map)
{
	int	**math_map;
	int	i;
	int	j;

	math_map = malloc(map->lines * sizeof(int *));
	i = 0;
	while (i < map->lines)
		math_map[i++] = malloc(map->columns * sizeof(int));
	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->columns)
		{
			if (map->terrain[i][j] == map->symbols[0])
				math_map[i][j] = 1;
			else
				math_map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (math_map);
}

int	**squarify(int **mathmap, int size, int line_len)
{
	int		i;
	int		j;

	i = 1;
	while (i < size)
	{
		j = 1;
		while (j < line_len)
		{
			if (mathmap[i][j] != 0)
				mathmap[i][j] = ft_min3(
						mathmap[i - 1][j],
						mathmap[i][j - 1],
						mathmap[i - 1][j - 1]
						) + 1;
			j++;
		}
		i++;
	}
	return (mathmap);
}

t_point	find_matrix_max(int **matrix, int size, int line_len)
{
	t_point	result;
	int		i;
	int		j;

	result.value = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < line_len)
		{
			if (matrix[i][j] > result.value)
			{
				result.value = matrix[i][j];
				result.x = i;
				result.y = j;
			}
			j++;
		}
		i++;
	}
	return (result);
}

void	solve_map(t_map *map)
{
	t_point	max;
	int		i;
	int		j;
	int		**mathmap;

	i = 0;
	j = 0;
	mathmap = squarify(mathify(map), map->lines, map->columns);
	max = find_matrix_max(mathmap, map->lines, map->columns);
	i = max.x;
	while (i > max.x - max.value)
	{
		j = max.y;
		while (j > max.y - max.value)
		{
			map->terrain[i][j] = map->symbols[2];
			j--;
		}
		i--;
	}
	ft_arr_arr_free((void **) mathmap, map->lines);
	free(mathmap);
}
