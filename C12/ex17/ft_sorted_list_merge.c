/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:17:14 by vegret            #+#    #+#             */
/*   Updated: 2022/07/28 19:03:24 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*tmp;

	if (begin_list)
	{
		tmp = begin_list;
		while (tmp->next)
			tmp = tmp->next;
		return (tmp);
	}
	return (begin_list);
}

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*tmp;

	tmp = ft_list_last(*begin_list1);
	if (tmp)
	{
		tmp->next = begin_list2;
		return ;
	}
	*begin_list1 = begin_list2;
}

void	ft_swap_data(t_list *cell1, t_list *cell2)
{
	void	*tmp;

	tmp = cell1->data;
	cell1->data = cell2->data;
	cell2->data = tmp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		swapped;
	t_list	*ptr1;
	t_list	*lptr;

	lptr = NULL;
	if (*begin_list == NULL)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		ptr1 = *begin_list;
		while (ptr1->next != lptr)
		{
			if ((*cmp)(ptr1->data, ptr1->next->data) > 0)
			{
				ft_swap_data(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1, cmp);
}
