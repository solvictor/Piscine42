/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:35:38 by vegret            #+#    #+#             */
/*   Updated: 2022/07/22 14:40:15 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_index(char *str, char c)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

int	nb_words(char *str, char *charset)
{
	int	nb_words;
	int	on_word;
	int	i;

	nb_words = 0;
	on_word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str_index(charset, str[i++]) == -1)
			on_word = 1;
		else if (on_word)
		{
			nb_words++;
			on_word = 0;
		}
	}
	if (on_word)
		nb_words++;
	return (nb_words);
}

int	*words_lengths(char *str, char *charset)
{
	int	*result;
	int	index;
	int	i;

	i = 0;
	index = 0;
	result = malloc(nb_words(str, charset) * sizeof(int));
	if (result == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str_index(charset, str[i]) == -1)
		{
			result[index]++;
			i++;
		}
		else
		{
			while (str_index(charset, str[i]) != -1)
				i++;
			index++;
		}
	}
	return (result);
}

void	str_cpy(char *charset, char *str, int *i, char *dest)
{
	int	j;

	j = *i;
	while (str_index(charset, str[*i]) == -1 && str[*i] != '\0')
	{
		dest[*i - j] = str[*i];
		(*i)++;
	}
	dest[*i - j] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		*lengths;
	int		i;
	int		index;

	result = malloc(nb_words(str, charset) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	index = 0;
	lengths = words_lengths(str, charset);
	while (str[i] != '\0' && str_index(charset, str[i]) != -1)
		i++;
	while (str[i] != '\0' && index < nb_words(str, charset))
	{
		result[index] = malloc((lengths[index] + 1) * sizeof(char));
		if (result[index] == NULL)
			return (NULL);
		str_cpy(charset, str, &i, result[index]);
		while (str[i] != '\0' && str_index(charset, str[i]) != -1)
			i++;
		index++;
	}
	return (result);
}
