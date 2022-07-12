/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 21:31:26 by vegret            #+#    #+#             */
/*   Updated: 2022/07/10 18:11:36 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	get_char(int column, int line, int max_column, int max_line)
{
	if (line == 0)
	{
		if (column == 0)
			return ('A');
		else if (column == max_column)
			return ('C');
		else
			return ('B');
	}
	else if (line == max_line)
	{
		if (column == 0)
			return ('C');
		else if (column == max_column)
			return ('A');
		else
			return ('B');
	}
	else
	{
		if (column == 0 || column == max_column)
			return ('B');
		else
			return (' ');
	}
}

void	rush(int x, int y)
{
	int	column;
	int	line;

	line = 0;
	while (line < y)
	{
		column = 0;
		while (column < x)
		{
			ft_putchar(get_char(column, line, x - 1, y - 1));
			column++;
		}
		ft_putchar('\n');
		line++;
	}
}
