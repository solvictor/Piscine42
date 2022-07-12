/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:48:29 by vegret            #+#    #+#             */
/*   Updated: 2022/07/07 17:01:28 by vegret           ###   ########.fr       */
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
