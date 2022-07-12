/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:17:48 by vegret            #+#    #+#             */
/*   Updated: 2022/07/12 15:50:51 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	result;

	result = 0;
	while (*str != '\0')
	{
		result++;
		str++;
	}
	return (result);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (size < dest_len)
		return (src_len + size);
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (dest_len + src_len > size - 1)
		dest[size] = '\0';
	else
		dest[ft_strlen(dest)] = '\0';
	return (dest_len + src_len);
}
