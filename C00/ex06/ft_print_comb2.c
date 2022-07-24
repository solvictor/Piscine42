/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:50:45 by vegret            #+#    #+#             */
/*   Updated: 2022/07/06 21:33:30 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnums2(int num)
{
	char	tens;
	char	ones;

	tens = '0' + num / 10;
	ones = '0' + num % 10;
	write(1, &tens, 1);
	write(1, &ones, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a < 100)
	{
		b = a + 1;
		while (b < 100)
		{
			putnums2(a);
			write(1, " ", 1);
			putnums2(b);
			if (a == 98 && b == 99)
			{
				return ;
			}
			write(1, ", ", 2);
			b++;
		}
		a++;
	}
}
