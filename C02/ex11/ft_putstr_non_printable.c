/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:34:04 by vegret            #+#    #+#             */
/*   Updated: 2022/07/11 11:30:37 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define HEXVALS "0123456789abcdef"

void	ft_puthexval(unsigned char c)
{
	unsigned char	printed;

	write(1, "\\", 1);
	printed = HEXVALS[c / 16];
	write(1, &printed, 1);
	printed = HEXVALS[c % 16];
	write(1, &printed, 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str < 32 || *str > 126)
			ft_puthexval(*str);
		else
			write(1, &*str, 1);
		str++;
	}
}
