/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:47:32 by vegret            #+#    #+#             */
/*   Updated: 2022/07/28 18:47:41 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;

	tmp = begin_list;
	while (tmp)
	{
		if ((*cmp)(tmp->data, data_ref) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
