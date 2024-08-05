/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:01:23 by lucmansa          #+#    #+#             */
/*   Updated: 2024/08/04 23:29:52 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

# define dictionary "numbers.dict"


typedef struct s_num_word
{
	char *number;
	char *words;
}	t_num_word;

t_num_word 	*parse(void);
int			check_exist(void);
char 		*get_dict(void);
int			dict_size(void);
void 		parse2(int j, int *i, char *str, t_num_word *tab);
int			ft_strlen(char *str);
int			ft_strncmp(char	*s1, char *s2);
void 		ft_search(char *str, t_num_word *tab);
void 		ft_search_one(char str, t_num_word *tab);
void		ft_putstr(char *str);
void 		divide(t_num_word *tab, char *str);
char		*ft_conv_ten(char *str);
void		ft_double(char *str, t_num_word *tab);
void 		ft_triple(char *str, t_num_word *tab);
void		*ft_calloc(int size);

#endif
