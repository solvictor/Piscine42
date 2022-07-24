/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:00:45 by vegret            #+#    #+#             */
/*   Updated: 2022/07/23 21:12:28 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_pair_list.h"
#include "ft.h"
#include "input_utils.h"

#define DEFAULT_PATH "ressources/numbers.dict"

char	*num_to_letters(long long unsigned nbr, t_pair_list *dict)
{
	char	*result;
	int		j;
	t_pair	*tmp;

	result = malloc(50000);
	if (result == NULL)
		return (NULL);
	if (nbr == 0)
		return (getbykey(dict, 0));
	while (nbr > 0)
	{
		j = size(dict) - 1;
		while (j >= 0)
		{
			tmp = get(dict, j);
			if (nbr == tmp->num)
			{
				result = ft_strcat(result, tmp->str);
				return (result);
			}
			if (nbr / tmp->num > 0)
			{
				if (nbr / tmp->num != 1)
					result = ft_strcat(result, getbykey(dict, nbr / tmp->num));
				result = ft_strcat(result, tmp->str);
				nbr -= (nbr / tmp->num) * tmp->num;
				if (nbr > 0)
					result = ft_strcat(result, " ");
			}
			j--;
		}
	}
	return (result);
}

int	main(int argc, char *argv[])
{
	int			input;
	t_pair_list	*dict;

	if (argc == 2)
	{
		input = ft_atoull(argv[1]);
		if (input >= 0)
		{
			dict = parse_dict(DEFAULT_PATH);
			if (dict == NULL)
				ft_putstr("Dict Error");
			else
				ft_putstr(num_to_letters(input, dict));
			write(1, "\n", 1);
			return (0);
		}
	}
	ft_putstr("Error\n");
	return (0);
}
