/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:19:51 by vegret            #+#    #+#             */
/*   Updated: 2022/07/27 23:19:35 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "input.h"
#include "map.h"
#include "ft.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_map	*map;
	char	*giga_buffer;
	int		ret;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			map = load_map(argv[i++], 1);
			handle_map(map);
			if (i != argc)
				ft_putstr("\n");
		}
	}
	else
	{
		giga_buffer = malloc(100000001);
		ret = read(0, giga_buffer, 100000001);
		giga_buffer[ret] = 0;
		map = load_map(giga_buffer, 0);
		handle_map(map);
	}
	return (0);
}
