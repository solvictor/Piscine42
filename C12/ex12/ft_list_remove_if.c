/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:47:32 by vegret            #+#    #+#             */
/*   Updated: 2022/07/28 19:28:16 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
							void (*free_fct)(void *))
{
	t_list	*root;
	t_list	*tmp;
	t_list	*next;

	root = *begin_list;
	tmp = *begin_list;
	while (root)
	{
		next = root->next;
		if ((cmp)(root->data, data_ref) == 0)
		{
			if (root == *begin_list)
				*begin_list = next;
			tmp->next = next;
			free(root);
		}
		tmp = root;
		root = next;
	}
}
