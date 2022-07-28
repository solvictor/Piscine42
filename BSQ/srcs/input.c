/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:32:45 by vegret            #+#    #+#             */
/*   Updated: 2022/07/27 23:19:26 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "map.h"
#include "ft.h"

char	*load_file(char *path)
{
	int		fd;
	char	*buf;
	int		size;

	buf = (char *) malloc(100000001 * sizeof(char));
	if (buf == NULL)
		return (NULL);
	fd = open(path, O_RDONLY, S_IROTH);
	if (fd == -1)
		return (NULL);
	size = read(fd, buf, 100000000);
	buf[size] = 0;
	close(fd);
	return (buf);
}

char	*parse_symbols(char *str)
{
	char	*symbols;
	int		strlen;

	strlen = ft_strlen(str);
	if (strlen < 4)
		return (NULL);
	symbols = malloc(sizeof(char) * 4);
	symbols[0] = str[strlen - 3];
	symbols[1] = str[strlen - 2];
	symbols[2] = str[strlen - 1];
	symbols[3] = '\0';
	return (symbols);
}

t_map	*load_map(char *path, int is_file)
{
	char	*file;
	char	*symbols;
	char	**terrain;
	int		lines;
	t_map	*result;

	if (is_file)
		file = load_file(path);
	else
		file = path;
	if (file == NULL)
		return (NULL);
	terrain = ft_split(file, "\n");
	if (!(terrain[0] && terrain[1]))
		return (NULL);
	lines = ft_antoi(terrain[0], ft_strlen(terrain[0]) - 3);
	symbols = parse_symbols(terrain[0]);
	free(terrain[0]);
	terrain++;
	result = create_map(terrain, lines, ft_strlen(terrain[0]), symbols);
	free(file);
	if (!is_valid_map(result))
		return (NULL);
	return (result);
}

void	handle_map(t_map *map)
{
	if (map == NULL)
		ft_putstr("map error");
	else
	{
		solve_map(map);
		print_map(map);
		free_map(map);
	}
	ft_putstr("\n");
}
