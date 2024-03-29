/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:35:38 by vegret            #+#    #+#             */
/*   Updated: 2022/07/26 20:20:38 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_str_contains(char c, char *str)
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
	int	start;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (ft_str_contains(str[i], charset) && str[i])
			i++;
		start = i;
		while (!(ft_str_contains(str[i], charset)) && str[i])
		{
			strs[k][i - start] = str[i];
			i++;
		}
		if (i > start)
			k++;
	}
}

void	strings_alloc(char *str, char *charset, char **strs)
{
	int	i;
	int	k;
	int	start;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (ft_str_contains(str[i], charset) && str[i])
			i++;
		start = i;
		while (!(ft_str_contains(str[i], charset)) && str[i])
			i++;
		if (i > start)
		{
			strs[k] = malloc(sizeof strs[k] * (i - start + 1));
			strs[k][i - start] = '\0';
			k++;
		}
	}
}

char	**words_alloc(char *str, char *charset, int *len_strs)
{
	char	**strs;
	int		i;
	int		start;

	i = 0;
	while (str[i])
	{
		while (ft_str_contains(str[i], charset) && str[i])
			i++;
		start = i;
		while (!(ft_str_contains(str[i], charset)) && str[i])
			i++;
		if (i > start)
			(*len_strs)++;
	}
	strs = malloc(sizeof strs * (*len_strs + 1));
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
