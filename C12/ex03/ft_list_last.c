/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:18:41 by vegret            #+#    #+#             */
/*   Updated: 2022/07/25 10:37:58 by vegret           ###   ########.fr       */
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
