/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:41:14 by vegret            #+#    #+#             */
/*   Updated: 2022/07/28 19:18:37 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*tmp;
	t_list	*new_element;

	new_element = ft_create_elem(data);
	if (*begin_list)
	{
		tmp = *begin_list;
		while (tmp->next)
		{
			if ((*cmp)(tmp->next->data, data) < 0)
			{
				new_element->next = tmp->next;
				tmp->next = new_element;
				return ;
			}
			tmp = tmp->next;
		}
		tmp->next = new_element;
	}
	else
		*begin_list = new_element;
}
