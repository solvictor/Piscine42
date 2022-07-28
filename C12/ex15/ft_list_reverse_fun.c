/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:54:27 by vegret            #+#    #+#             */
/*   Updated: 2022/07/28 18:47:12 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	*ft_list_data_at(t_list *begin_list, unsigned int nbr)
{
	t_list	*tmp;

	tmp = begin_list;
	while (tmp)
	{
		if (nbr == 0)
			return (tmp->data);
		tmp = tmp->next;
		nbr--;
	}
	return (0);
}

void	ft_list_set_data_at(t_list *begin_list, void *data, unsigned int nbr)
{
	t_list	*tmp;

	tmp = begin_list;
	while (tmp)
	{
		if (nbr == 0)
		{
			tmp->data = data;
			return ;
		}
		tmp = tmp->next;
		nbr--;
	}
}

int	ft_list_size(t_list *begin_list)
{
	t_list	*tmp;
	int		size;

	tmp = begin_list;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		i;
	int		size;
	void	*tmp;

	i = 0;
	size = ft_list_size(begin_list);
	while (i < size / 2)
	{
		tmp = ft_list_data_at(begin_list, i);
		ft_list_set_data_at(
			begin_list,
			ft_list_data_at(begin_list, size - i - 1),
			i);
		ft_list_set_data_at(
			begin_list,
			tmp,
			size - i - 1);
		i++;
	}
}
