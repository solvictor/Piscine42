/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:30:28 by vegret            #+#    #+#             */
/*   Updated: 2022/07/27 18:35:19 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "map.h"

t_map	*load_map(char *path, int is_file);
char	**parse_stdin(char *map, int lines, int col);

#endif