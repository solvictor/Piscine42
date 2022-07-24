/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:24:45 by vegret            #+#    #+#             */
/*   Updated: 2022/07/13 16:40:03 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char const *argv[])
{
	int	i;

	i = 0;
	while (argc - i > 1)
	{
		while (*argv[argc - i - 1] != '\0')
		{
			write(1, &*argv[argc - i - 1], 1);
			argv[argc - i - 1]++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
