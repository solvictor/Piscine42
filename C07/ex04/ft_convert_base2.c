/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:05:19 by vegret            #+#    #+#             */
/*   Updated: 2022/07/21 18:45:47 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	str_char_index(char *str, char c)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == c)
			return (index);
		index++;
	}
	return (-1);
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

int	check_base(char *base)
{
	int	base_len;

	if (str_char_index(base, '+') != -1 || str_char_index(base, '-') != -1
		|| str_char_index(base, ' ') != -1 || str_char_index(base, '\n') != -1
		|| str_char_index(base, '\t') != -1 || str_char_index(base, '\r') != -1
		|| str_char_index(base, '\v') != -1 || str_char_index(base, '\f') != -1)
		return (0);
	if (!is_str_uniq(base))
		return (0);
	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	return (base_len);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	negative;
	int	base_len;
	int	i;

	result = 0;
	base_len = check_base(base);
	i = get_start_char(str, &negative);
	while (str_char_index(base, str[i]) != -1)
	{
		result = result * base_len + (str_char_index(base, str[i++]));
	}
	return (result * negative);
}
