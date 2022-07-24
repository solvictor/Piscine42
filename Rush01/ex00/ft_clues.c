/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clues.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:33:55 by ple-lez           #+#    #+#             */
/*   Updated: 2022/07/17 15:51:04 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_line_clues_right_left(int **grid, int y, int *clues)
{
	int	i;
	int	max;
	int	res;

	max = 0;
	res = 0;
	i = 3;
	while (i >= 0)
	{
		if (grid[y][i] > max)
		{
			max = grid[y][i];
			res++;
		}
		i--;
	}
	if (clues[12 + y] != res)
		return (0);
	return (1);
}

int	ft_check_line_clues(int **grid, int y, int *clues)
{
	int	i;
	int	max;
	int	res;

	max = 0;
	res = 0;
	i = 0;
	while (i < 4)
	{
		if (grid[y][i] > max)
		{
			max = grid[y][i];
			res++;
		}
		i++;
	}
	if (clues[8 + y] != res)
		return (0);
	return (ft_check_line_clues_right_left(grid, y, clues));
}

int	ft_check_col_clues_down_top(int **grid, int x, int *clues)
{
	int	i;
	int	max;
	int	res;

	max = 0;
	res = 0;
	i = 3;
	while (i >= 0)
	{
		if (grid[i][x] > max)
		{
			max = grid[i][x];
			res++;
		}
		i--;
	}
	if (clues[4 + x] != res)
		return (0);
	return (1);
}

int	ft_check_col_clues(int **grid, int x, int *clues)
{
	int	i;
	int	max;
	int	res;

	max = 0;
	res = 0;
	i = 0;
	while (i < 4)
	{
		if (grid[i][x] > max)
		{
			max = grid[i][x];
			res++;
		}
		i++;
	}
	if (clues[x] != res)
		return (0);
	return (ft_check_col_clues_down_top(grid, x, clues));
}
