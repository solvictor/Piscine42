/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:27:36 by vegret            #+#    #+#             */
/*   Updated: 2022/07/19 18:30:40 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define HEXVALS "0123456789abcdef"

void	print_hex(unsigned char c)
{
	write(1, &HEXVALS[c / 16], 1);
	write(1, &HEXVALS[c % 16], 1);
}

void	print_address(void *addr)
{
	unsigned long	ull_addr;
	char			tab[16];
	int				i;

	ull_addr = (unsigned long) addr;
	i = 0;
	while (ull_addr > 0)
	{
		tab[i++] = HEXVALS[ull_addr % 16];
		ull_addr /= 16;
	}
	while (i < 16)
		tab[i++] = '0';
	i--;
	while (i >= 0)
		write(1, &tab[i--], 1);
	write(1, ": ", 2);
}

void	print_hex_content(void *addr, unsigned int size)
{
	unsigned char		*string_addr;
	unsigned int		i;
	unsigned int		k;

	string_addr = (unsigned char *) addr;
	i = 0;
	k = 0;
	while (i < 16)
	{
		if (size < 16 && i >= size)
		{
			write(1, "  ", 2);
			i++;
		}
		else
		{
			print_hex(string_addr[k++]);
			i++;
		}
		if (i % 2 == 0)
			write(1, " ", 1);
	}
}

void	print_content(void *addr, unsigned int size)
{
	unsigned char				*string_addr;
	unsigned int				i;

	string_addr = (unsigned char *) addr;
	i = 0;
	while (i < size)
	{
		if (string_addr[i] > 31 && 127 > string_addr[i])
			write(1, &string_addr[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (size - i < 16)
		{
			print_address(addr + i);
			print_hex_content(addr + i, size - i);
			print_content(addr + i, size - i);
		}
		else
		{
			print_address(addr + i);
			print_hex_content(addr + i, 16);
			print_content(addr + i, 16);
		}
		i += 16;
	}
	return (addr);
}
