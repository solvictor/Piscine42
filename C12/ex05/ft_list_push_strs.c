/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:39:01 by vegret            #+#    #+#             */
/*   Updated: 2022/07/28 18:59:40 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*result;
	int		i;

	i = 0;
	result = NULL;
	while (i < size)
	{
		if (result)
			ft_list_push_front(&result, strs[i]);
		else
			result = ft_create_elem(strs[i]);
		i++;
	}
	return (result);
}
