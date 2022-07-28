/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:57:32 by vegret            #+#    #+#             */
/*   Updated: 2022/07/26 11:59:51 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
