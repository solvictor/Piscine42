/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:58:54 by vegret            #+#    #+#             */
/*   Updated: 2022/07/23 21:11:22 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_UTILS_H
# define INPUT_UTILS_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "ft_pair_list.h"
# include "ft.h"
# include "ft_split.h"

char	*load_file(char *path)
{
	int		fd;
	char	*buf;
	int		size;

	buf = (char *) malloc(4096 * sizeof(char));
	if (buf == NULL)
		return (NULL);
	fd = open(path, O_RDONLY, S_IROTH);
	if (fd == -1)
		return (NULL);
	size = read(fd, buf, 4095);
	buf[size] = 0;
	close(fd);
	return (buf);
}

unsigned long long	get_start_char(char *str, int *negative)
{
	unsigned long long	result;

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

unsigned long long	ft_atoull(char *str)
{
	unsigned long long	result;
	int					negative;
	unsigned long long	i;

	result = 0;
	i = get_start_char(str, &negative);
	while (str[i] <= '9' && str[i] >= '0')
		result = result * 10 + (str[i++] - '0');
	return (result * negative);
}

char	*get_letters(char *line)
{
	char	*result;
	int		i;
	int		ressize;

	i = ft_strlen(line);
	ressize = 1;
	while (line[i - 1] != ' ')
	{
		ressize++;
		i--;
	}
	result = (char *) malloc(ressize * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strcpy(result, line + i);
	return (result);
}

t_pair_list	*parse_dict(char *path)
{
	int				i;
	t_pair_list		*result;
	t_pair			*test;
	char			*dict;
	char			**lines;

	dict = load_file(path);
	result = NULL;
	if (dict == NULL)
		return (NULL);
	lines = ft_split(dict, "\n");
	i = 0;
	while (i < nb_words(dict, "\n"))
	{
		test = make_pair(ft_atoull(lines[i]), get_letters(lines[i]));
		result = add_element(result, test);
		i++;
	}
	return (result);
}

#endif