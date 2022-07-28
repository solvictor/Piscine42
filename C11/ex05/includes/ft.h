/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:40:24 by vegret            #+#    #+#             */
/*   Updated: 2022/07/24 21:27:31 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>

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

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, (str + i), 1);
		i++;
	}
}

int	get_start_char(char *str, int *negative)
{
	int	result;

	result = 0;
	*negative = 1;
	while (str[result] == ' ' || str[result] == '\t' || str[result] == '\n'
		|| str[result] == '\r' || str[result] == '\v' || str[result] == '\f')
		result++;
	while (str[result] == '+' || str[result] == '-')
		if (str[result++] == '-')
			*negative *= -1;
	return (result);
}

int	ft_atoi(char *str)
{
	int	result;
	int	negative;
	int	i;

	result = 0;
	i = get_start_char(str, &negative);
	while (str[i] <= '9' && str[i] >= '0')
		result = result * 10 + (str[i++] - '0');
	return (result * negative);
}

#endif