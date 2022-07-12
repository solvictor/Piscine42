/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:23:11 by vegret            #+#    #+#             */
/*   Updated: 2022/07/09 17:06:42 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

int	ft_char_is_alpha(char c)
{
	return ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'));
}

int	ft_char_is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

char	*ft_strcapitalize(char *str)
{
	int		start_word;
	char	*tmp;

	tmp = str;
	start_word = 1;
	str = ft_strlowcase(str);
	while (*str != '\0')
	{
		if (ft_char_is_lowercase(*str) && start_word)
		{
			*str -= 32;
			start_word = 0;
		}
		else if (!ft_char_is_alpha(*str))
			start_word = 1;
		if (ft_char_is_numeric(*str))
			start_word = 0;
		str++;
	}
	return (tmp);
}
