/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:06:23 by vegret            #+#    #+#             */
/*   Updated: 2022/07/27 23:19:51 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	get_start_char(char *str, int *negative)
{
	int	result;

	result = 0;
	*negative = 1;
	while (str[result] == ' ' || str[result] == '\t' || str[result] == '\n'
		|| str[result] == '\r' || str[result] == '\v' || str[result] == '\f')
		result++;
	while (str[result] == '+' || str[result] == '-')
		if (str[result++] == '-')
			*negative *= -1;
	return (result);
}

int	ft_antoi(char *str, int n)
{
	int	result;
	int	negative;
	int	i;

	result = 0;
	i = get_start_char(str, &negative);
	while (str[i] <= '9' && str[i] >= '0' && i < n)
		result = result * 10 + (str[i++] - '0');
	return (result * negative);
}

void	ft_arr_arr_free(void **arr, int size)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (i < size)
		{
			free(arr[i]);
			i++;
		}
	}
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_min3(int a, int b, int c)
{
	return (ft_min(ft_min(a, b), c));
}
