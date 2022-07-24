/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:28:51 by vegret            #+#    #+#             */
/*   Updated: 2022/07/14 14:18:35 by vegret           ###   ########.fr       */
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

int	is_str_uniq(char *str)
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

void	ft_putnbr_base_aux(unsigned int nbr, char *base, int base_len)
{
	if (nbr == 0)
		return ;
	ft_putnbr_base_aux(nbr / base_len, base, base_len);
	write(1, &base[nbr % base_len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	if (base_len < 2 || !is_str_uniq(base))
		return ;
	if (ft_str_contains(base, '+') || ft_str_contains(base, '-'))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	ft_putnbr_base_aux(nbr, base, base_len);
}
