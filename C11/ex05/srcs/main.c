/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:24:24 by vegret            #+#    #+#             */
/*   Updated: 2022/07/27 13:36:58 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_operations.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	do_op(int a, t_operation *op, int b)
{
	if (op == 0)
		ft_putnbr(0);
	else
	{
		if (b == 0)
		{
			if (op->function == &modulo)
			{
				ft_putstr("Stop : modulo by zero\n");
				return ;
			}
			if (op->function == &divides)
			{
				ft_putstr("Stop : division by zero\n");
				return ;
			}	
		}
		ft_putnbr(op->function(a, b));
	}
	ft_putstr("\n");
}

void	load_operations(t_operation	*tab)
{
	tab[0].symbol = '+';
	tab[0].function = &plus;
	tab[1].symbol = '-';
	tab[1].function = &minus;
	tab[2].symbol = '*';
	tab[2].function = &times;
	tab[3].symbol = '/';
	tab[3].function = &divides;
	tab[4].symbol = '%';
	tab[4].function = &modulo;
}

t_operation	*parse_op(char *op, t_operation *operations)
{
	int	i;

	if (ft_strlen(op) == 1 && operations != 0)
	{
		i = 0;
		while (i < 5)
		{
			if (operations[i].symbol == op[0])
				return (&operations[i]);
			i++;
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_operation	ops[5];

	load_operations(ops);
	if (argc == 4)
		do_op(ft_atoi(argv[1]), parse_op(argv[2], ops), ft_atoi(argv[3]));
	return (0);
}
