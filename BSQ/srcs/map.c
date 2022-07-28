/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:48:06 by vegret            #+#    #+#             */
/*   Updated: 2022/07/27 23:18:55 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "map.h"
#include "ft.h"

t_map	*create_map(char **terrain, int lines, int columns, char *symbols)
{
	t_map	*result;

	result = malloc(sizeof(t_map));
	result->terrain = terrain;
	result->lines = lines;
	result->columns = columns;
	result->symbols = symbols;
	return (result);
}

int	is_valid_terrain(t_map *map)
{
	int	i;

	i = 0;
	if (map->lines < 1 || map->columns < 1)
		return (0);
	while (map->terrain[i])
	{
		if (ft_strlen(map->terrain[i]) != map->columns
			|| !ft_str_only_contains(map->terrain[i], map->symbols))
			return (0);
		i++;
	}
	if (i == map->lines)
		return (1);
	ft_arr_arr_free((void **) map->terrain, i);
	return (0);
}

int	is_valid_map(t_map *map)
{
	int	i;

	i = 0;
	if (map == NULL || map->symbols == NULL || map->terrain == NULL)
		return (0);
	while (map->symbols[i])
	{
		if (i > 2 || map->symbols[i] < 31 || map->symbols[i] > 126
			|| ft_str_char_count(map->symbols, map->symbols[i]) > 1)
			return (0);
		i++;
	}
	return (is_valid_terrain(map));
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->lines)
	{
		ft_putstr(map->terrain[i]);
		if (i != map->lines - 1)
			ft_putstr("\n");
		i++;
	}
}

void	free_map(t_map *map)
{
	if (map)
	{
		ft_arr_arr_free((void **) map->terrain, map->lines);
		free(map->symbols);
	}
	free(map);
}
