/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:11:00 by vegret            #+#    #+#             */
/*   Updated: 2022/07/11 21:45:33 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_aux(int nbr)
{
	char	display_nbr;

	if (nbr == 0)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	display_nbr = '0' + (nbr % 10);
	ft_putnbr_aux(nbr / 10);
	write(1, &display_nbr, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	ft_putnbr_aux(nbr);
}

void	ft_print_hex_adress(void *addr)
{
	
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_print_hex_adress(&addr[i]);
		write(1, ": ", 2);
		write(1, "\n", 1);
		i+=16;
	}
	return addr;
}
