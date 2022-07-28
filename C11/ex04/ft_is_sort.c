/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:31:13 by vegret            #+#    #+#             */
/*   Updated: 2022/07/24 20:21:08 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_sort_descending(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	j;

	i = 0;
	while (i < length - 1)
	{
		j = i + 1;
		while (j < length && f(tab[i], tab[j]) == 0)
			j++;
		while (j < length)
		{
			if (f(tab[i], tab[j]) < 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sort_ascending(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	j;

	i = 0;
	while (i < length - 1)
	{
		j = i + 1;
		while (j < length && f(tab[i], tab[j]) == 0)
			j++;
		while (j < length)
		{
			if (f(tab[i], tab[j]) > 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	return (is_sort_descending(tab, length, f)
		|| is_sort_ascending(tab, length, f));
}
