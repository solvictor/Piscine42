/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:35:38 by vegret            #+#    #+#             */
/*   Updated: 2022/07/27 23:09:11 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"

int	ft_str_contains(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

void	strings_copy(char *str, char *charset, char **strs)
{
	int	i;
	int	k;
	int	end_last;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (ft_str_contains(charset, str[i]) && str[i])
			i++;
		end_last = i;
		while (!(ft_str_contains(charset, str[i])) && str[i])
		{
			strs[k][i - end_last] = str[i];
			i++;
		}
		if (i > end_last)
			k++;
	}
}

void	strings_alloc(char *str, char *charset, char **strs)
{
	int	i;
	int	k;
	int	end_last;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (ft_str_contains(charset, str[i]) && str[i])
			i++;
		end_last = i;
		while (!(ft_str_contains(charset, str[i])) && str[i])
			i++;
		if (i > end_last)
		{
			strs[k] = malloc(sizeof(char *) * (i - end_last + 1));
			strs[k][i - end_last] = '\0';
			k++;
		}
	}
}

char	**words_alloc(char *str, char *charset, int *len_strs)
{
	char	**strs;
	int		i;
	int		end_last;

	i = 0;
	while (str[i])
	{
		while (ft_str_contains(charset, str[i]) && str[i])
			i++;
		end_last = i;
		while (!(ft_str_contains(charset, str[i])) && str[i])
			i++;
		if (i > end_last)
			(*len_strs)++;
	}
	strs = malloc(sizeof(char **) * (*len_strs + 1));
	if (strs == NULL)
		return (NULL);
	strs[*len_strs] = NULL;
	return (strs);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		len_strs;

	len_strs = 0;
	strs = words_alloc(str, charset, &len_strs);
	if (len_strs == 0)
		return (strs);
	strings_alloc(str, charset, strs);
	strings_copy(str, charset, strs);
	return (strs);
}
