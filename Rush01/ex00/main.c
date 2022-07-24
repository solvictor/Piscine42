/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:11:18 by vegret            #+#    #+#             */
/*   Updated: 2022/07/17 15:22:26 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_is_valid(int **grid, int x, int y, int *clues);
int		is_valid_input(char *str);
int		*split_and_convert(char *str);
void	print_grid(int **grid, int side_len);

int	ft_solver(int **grid, int x, int y, int *clues)
{
	int	i;
	int	res;

	i = 1;
	if (y == 4)
	{
		print_grid(grid, 4);
		return (1);
	}
	while (i <= 4)
	{
		grid[y][x] = i;
		if (ft_is_valid(grid, x, y, clues))
		{
			if (x < 3)
				res = ft_solver(grid, x + 1, y, clues);
			else
				res = ft_solver(grid, 0, y + 1, clues);
			if (res)
				return (1);
		}
		i++;
	}
	grid[y][x] = 0;
	return (0);
}

int	**ft_init_grid(void)
{
	int	i;
	int	**grid;

	i = 0;
	grid = (int **) malloc(sizeof(int *) * 4);
	if (!grid)
		return (NULL);
	while (i < 4)
	{
		grid[i] = (int *) malloc(sizeof(int) * 4);
		if (!grid[i])
			return (NULL);
		i++;
	}
	return (grid);
}

void	ft_free_grid(int **grid)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int	main(int argc, char *argv[])
{
	int	*converted;
	int	**grid;
	int	res;

	grid = ft_init_grid();
	if (argc == 2)
	{
		if (is_valid_input(argv[1]))
		{
			converted = split_and_convert(argv[1]);
			if (converted != NULL)
			{
				res = ft_solver(grid, 0, 0, converted);
				if (!res)
					write(1, "Error\n", 6);
				ft_free_grid(grid);
				return (0);
			}
		}
	}
	ft_free_grid(grid);
	write(1, "Error\n", 6);
	return (0);
}
