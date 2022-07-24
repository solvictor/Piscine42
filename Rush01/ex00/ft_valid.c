/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:23:19 by ple-lez           #+#    #+#             */
/*   Updated: 2022/07/17 15:04:43 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_line_clues(int **grid, int y, int *clues);
int	ft_check_col_clues(int **grid, int x, int *clues);

int	ft_check_line(int **grid, int x, int y)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i != x)
			if (grid[y][x] == grid[y][i])
				return (0);
		i++;
	}
	return (1);
}

int	ft_check_col(int **grid, int x, int y)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i != y)
			if (grid[y][x] == grid[i][x])
				return (0);
		i++;
	}
	return (1);
}

int	ft_is_valid(int **grid, int x, int y, int *clues)
{
	if (!ft_check_line(grid, x, y))
		return (0);
	if (!ft_check_col(grid, x, y))
		return (0);
	if (x == 3)
		if (!ft_check_line_clues(grid, y, clues))
			return (0);
	if (y == 3)
		if (!ft_check_col_clues(grid, x, clues))
			return (0);
	return (1);
}
