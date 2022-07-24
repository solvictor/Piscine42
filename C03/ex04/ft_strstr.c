/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:03:08 by vegret            #+#    #+#             */
/*   Updated: 2022/07/12 11:24:48 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	j;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		j = 0;
		while (to_find[j] == str[j])
		{
			j++;
			if (to_find[j] == '\0')
				return (str);
		}
		str++;
	}
	return ('\0');
}
