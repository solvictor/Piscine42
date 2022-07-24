/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:47:10 by vegret            #+#    #+#             */
/*   Updated: 2022/07/17 14:17:22 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_int_arr(int arr[])
{
	char	display_nbr;
	int		i;

	i = 0;
	while (i < 10)
	{
		display_nbr = '0' + arr[i++];
		write(1, &display_nbr, 1);
	}
	write(1, "\n", 1);
	return (1);
}

int	has_collision(int column, int arr[])
{
	int	i;
	int	distance_ver;

	i = 0;
	while (i++ < 10)
	{
		if (column != i)
		{
			distance_ver = arr[column] - arr[i];
			distance_ver *= (1 + (distance_ver < 0) * -2);
			if (distance_ver == (column - i) * (1 + (column - i < 0) * -2))
				return (1);
		}
	}
	return (0);
}

int	array_index(int arr[], int size, int element)
{
	int	i;

	i = 0;
	while (i < size)
		if (arr[i++] == element)
			return (i);
	return (-1);
}

int	test_grids(int column, int arr[])
{
	int	test;
	int	working_grids;

	working_grids = 0;
	test = 0;
	if (column == 10)
	{
		while (test < 10)
			if (has_collision(test++, arr))
				return (0);
		return (print_int_arr(arr));
	}
	else
	{
		while (test < 10)
		{
			if (array_index(arr, column, test) == -1)
			{
				arr[column] = test;
				working_grids += test_grids(column + 1, arr);
			}
			test++;
		}
	}
	return (working_grids);
}

int	ft_ten_queens_puzzle(void)
{
	int	arr[10];

	return (test_grids(0, arr));
}
