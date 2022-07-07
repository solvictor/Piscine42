/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:36:32 by vegret            #+#    #+#             */
/*   Updated: 2022/07/07 15:00:47 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		tmp = tab[i];
		j = i;
		while (j > 0 && tab[j - 1] > tmp)
		{
			tab[j] = tab[j - 1];
			j--;
		}
		tab[j] = tmp;
		i++;
	}
}
