/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:38:20 by vegret            #+#    #+#             */
/*   Updated: 2022/07/11 14:27:14 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_alpha(char c)
{
	return ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'));
}

int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if (!(ft_char_is_alpha(*str) || *str == '\0'))
			return (0);
		str++;
	}
	return (1);
}
