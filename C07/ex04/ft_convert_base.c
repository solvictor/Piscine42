/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:05:21 by vegret            #+#    #+#             */
/*   Updated: 2022/07/24 14:49:48 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	check_base(char *base);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	result_length(int nbr, int base_to_len)
{
	int	result;

	result = 0;
	if (nbr <= 0)
		result++;
	while (nbr != 0)
	{
		nbr /= base_to_len;
		result++;
	}
	return (result);
}

void	tour(char *result, int *i, int *b10nbr, char *base_to)
{
	int	base_to_len;
	int	index;

	base_to_len = ft_strlen(base_to);
	index = *b10nbr % base_to_len;
	if (index < 0)
		index *= -1;
	if (result[*i] != '-')
		result[*i] = base_to[index];
	*b10nbr /= base_to_len;
	(*i)--;
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		b10nbr;
	int		base_to_len;
	int		i;
	int		result_len;
	char	*result;

	if (check_base(base_from) < 2 || check_base(base_to) < 2)
		return (NULL);
	b10nbr = ft_atoi_base(nbr, base_from);
	base_to_len = ft_strlen(base_to);
	result_len = result_length(b10nbr, base_to_len);
	result = malloc((result_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (b10nbr < 0)
		result[0] = '-';
	i = result_len - 1;
	while (i >= 0)
		tour(result, &i, &b10nbr, base_to);
	result[result_len] = '\0';
	return (result);
}
