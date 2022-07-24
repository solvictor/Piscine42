/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:24:44 by vegret            #+#    #+#             */
/*   Updated: 2022/07/21 18:55:46 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_len;
	int	i;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

int	get_alloc(int size, char **strs, char *sep)
{
	int	alloc;
	int	i;
	int	seplen;

	if (size == 0)
		return (1);
	alloc = 0;
	i = 0;
	seplen = ft_strlen(sep);
	while (i < size)
		alloc += ft_strlen(strs[i++]);
	return (alloc + (seplen * (size - 1)) + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*result;

	result = malloc(get_alloc(size, strs, sep) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	if (size == 0)
		return (result);
	i = 0;
	while (i < size)
	{
		result = ft_strcat(result, strs[i]);
		if (i < size - 1)
			result = ft_strcat(result, sep);
		i++;
	}
	return (result);
}
