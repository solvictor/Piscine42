/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:11:23 by vegret            #+#    #+#             */
/*   Updated: 2022/07/09 11:54:28 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

char	*ft_strlowcase(char *str)
{
	char	*tmp;

	tmp = str;
	while (*str != '\0')
	{
		if (ft_char_is_uppercase(*str))
			*str += 32;
		str++;
	}
	return (tmp);
}
