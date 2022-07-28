/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:00:41 by vegret            #+#    #+#             */
/*   Updated: 2022/07/28 13:42:31 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

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
