/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 21:08:41 by vegret            #+#    #+#             */
/*   Updated: 2022/07/26 15:06:35 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPERATIONS_H
# define FT_OPERATIONS_H

typedef struct s_opration
{
	char	symbol;
	int		(*function)(int, int);
}			t_operation;

int	plus(int a, int b)
{
	return (a + b);
}

int	minus(int a, int b)
{
	return (a - b);
}

int	times(int a, int b)
{
	return (a * b);
}

int	divides(int a, int b)
{
	return (a / b);
}

int	modulo(int a, int b)
{
	return (a % b);
}

#endif