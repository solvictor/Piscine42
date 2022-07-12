/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:28:51 by vegret            #+#    #+#             */
/*   Updated: 2022/07/12 15:21:27 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_contains(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_str_uniq(char *str)
{
	int	i;
	int	j;
	int	letter_count;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		letter_count = 0;
		while (str[j] != '\0')
		{
			if (str[j] == str[i])
				letter_count++;
			j++;
		}
		if (letter_count > 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_pow(int n, int k)
{
	if (k == 0)
		return (1);
	if (k == 1)
		return (n);
	return (n * ft_pow(n, k - 1));
}

void	ft_putnbr_base_aux(int nbr, char *base, int base_len)
{
	if (nbr == 0)
		return ;
	ft_putnbr_base_aux(nbr / base_len, base, base_len);
	write(1, &base[nbr % base_len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{ // TODO Prendre en compte les negatifs
	int	base_len;

	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	if (base_len < 2 || !ft_str_uniq(base))
		return ;
	if (ft_str_contains(base, '+') || ft_str_contains(base, '-'))
		return ;
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	ft_putnbr_base_aux(nbr, base, base_len);

}
