/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:04:00 by vegret            #+#    #+#             */
/*   Updated: 2022/07/28 19:29:04 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list	*tmp;

	if (nbr < 0)
		return (NULL);
	tmp = begin_list;
	while (tmp)
	{
		if (nbr == 0)
			return (tmp);
		tmp = tmp->next;
		nbr--;
	}
	return (NULL);
}
