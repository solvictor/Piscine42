/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:17:48 by vegret            #+#    #+#             */
/*   Updated: 2022/07/13 10:41:29 by vegret           ###   ########.fr       */
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
	char			*dest_copy;
	char			*src_copy;
	unsigned int	size_copy;
	unsigned int	dest_len;

	dest_copy = dest;
	src_copy = src;
	size_copy = size;
	while (size_copy-- != 0 && *dest_copy != '\0')
		dest_copy++;
	dest_len = dest_copy - dest;
	size_copy = size - dest_len;
	if (size_copy == 0)
		return (dest_len + ft_strlen(src_copy));
	while (*src_copy != '\0')
	{
		if (size_copy != 1)
		{
			*dest_copy++ = *src_copy;
			size_copy--;
		}
		src_copy++;
	}
	*dest_copy = '\0';
	return (dest_len + (src_copy - src));
}
