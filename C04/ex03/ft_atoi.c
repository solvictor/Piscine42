/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:40:34 by vegret            #+#    #+#             */
/*   Updated: 2022/07/12 11:10:32 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_negative(char *str)
{
	int	negative;
	int	i;

	negative = 0;
	i = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative = !negative;
		i++;
	}
	return (negative);
}

char	*ft_str_remove_space(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

char	*ft_str_remove_signs(char *str)
{
	while (*str == '+' || *str == '-')
		str++;
	return (str);
}

int	ft_get_pow_ten(char *str)
{
	int	pow_ten;

	pow_ten = 1;
	while (*str <= '9' && *str >= '0')
	{
		pow_ten *= 10;
		str++;
	}
	return (pow_ten / 10);
}

int	ft_atoi(char *str)
{
	int	result;
	int	negative;
	int	pow_ten;
	int	i;

	result = 0;
	i = 0;
	str = ft_str_remove_space(str);
	negative = ft_str_is_negative(str);
	str = ft_str_remove_signs(str);
	pow_ten = ft_get_pow_ten(str);
	while (str[i] <= '9' && str[i] >= '0')
	{
		result += (str[i] - '0') * (pow_ten);
		pow_ten /= 10;
		i++;
	}
	if (negative)
		result *= -1;
	return (result);
}
