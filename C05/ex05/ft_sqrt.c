/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:11:46 by vegret            #+#    #+#             */
/*   Updated: 2022/07/17 21:25:13 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	result;

	result = 0;
	while (result * result < nb)
		result++;
	if (result * result == nb)
		return (result);
	return (0);
}
