/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:12:32 by vegret            #+#    #+#             */
/*   Updated: 2022/07/27 23:10:14 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

int		ft_antoi(char *str, int n);
char	**ft_split(char *str, char *charset);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
int		ft_str_char_count(char *str, char c);
int		ft_str_only_contains(char *str, char *constructors);
int		ft_str_contains(char *str, char c);
void	ft_arr_arr_free(void **arr, int size);
int		ft_min3(int a, int b, int c);

#endif