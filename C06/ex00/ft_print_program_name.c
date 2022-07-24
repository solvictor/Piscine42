/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:13:01 by vegret            #+#    #+#             */
/*   Updated: 2022/07/15 11:40:17 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char const *argv[])
{
	(void) argc;
	while (*argv[0] != '\0')
	{
		write(1, &*argv[0], 1);
		argv[0]++;
	}
	write(1, "\n", 1);
	return (0);
}
