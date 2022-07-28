/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pair_list.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 10:24:05 by vegret            #+#    #+#             */
/*   Updated: 2022/07/26 16:13:52 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PAIR_LIST_H
# define FT_PAIR_LIST_H
# include <stdlib.h>
# include "ft.h"

typedef struct s_pair
{
	long long unsigned	num;
	char				*str;
}	t_pair;

typedef struct s_pair_list
{
	struct s_pair_list	*next;
	t_pair				*pair;
}	t_pair_list;

t_pair	*make_pair(long long unsigned num, char *str)
{
	t_pair	*result;

	result = malloc(sizeof(t_pair));
	result->num = num;
	result->str = ft_strdup(str);
	return (result);
}

t_pair_list	*add_element(t_pair_list *lst, t_pair *element)
{
	t_pair_list	*tmp;

	if (lst == NULL)
	{
		lst = malloc(sizeof(t_pair_list));
		lst->pair = element;
		lst->next = NULL;
		return (lst);
	}
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = malloc(sizeof(t_pair_list));
	tmp->next->pair = element;
	tmp->next->next = NULL;
	return (lst);
}

char	*getbykey(t_pair_list *lst, long long unsigned key)
{
	t_pair_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->pair->num == key)
			return (tmp->pair->str);
		tmp = tmp->next;
	}
	return (NULL);
}

int	size(t_pair_list *lst)
{
	int			size;
	t_pair_list	*tmp;

	size = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

t_pair	*get(t_pair_list *lst, int index)
{
	int			i;
	t_pair_list	*tmp;

	if (index < 0 || index >= size(lst))
		return (NULL);
	i = 0;
	tmp = lst;
	while (tmp)
	{
		if (i == index)
			return (tmp->pair);
		i++;
		tmp = tmp->next;
	}
	return (NULL);
}

#endif
