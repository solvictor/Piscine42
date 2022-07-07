/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:56:36 by vegret            #+#    #+#             */
/*   Updated: 2022/07/07 12:03:34 by vegret           ###   ########.fr       */
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
	ft_putnbr_aux(nbr);
}

int	ft_pow(int n, int k)
{
	if (k == 0)
	{
		return (1);
	}
	if (k == 1)
	{
		return (n);
	}
	return (n * ft_pow(n, k - 1));
}

void	ft_print_combn_aux(int put_zero, int mini, int digits, int perm)
{
	int	i;
	int	test;

	if (digits == 0)
	{
		if (put_zero > 1 && perm < put_zero)
			write(1, "0", 1);
		ft_putnbr(perm);
		test = 1;
		while ((perm % ft_pow(10, test)) / ft_pow(10, test - 1) == 10 - test)
		{
			if (10 - test == perm / put_zero)
				return ;
			test++;
		}
		write(1, ", ", 2);
		return ;
	}
	i = mini;
	while (i < 10)
	{
		ft_print_combn_aux(put_zero, i + 1, digits - 1, 10 * perm + i);
		i++;
	}
}

void	ft_print_combn(int n)
{
	ft_print_combn_aux(ft_pow(10, n - 1), 0, n, 0);
}
