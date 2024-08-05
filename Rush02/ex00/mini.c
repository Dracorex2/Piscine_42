/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:36:32 by tle-saut          #+#    #+#             */
/*   Updated: 2024/08/04 16:26:59 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "header1.h"
char	*ft_strdup(char *src)
{
	int			i;
	char		*copy;

	i = 0;
	while (src[i])
		i++;
	copy = malloc((i + 1) * sizeof(char));
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
int	ft_strncmp(char	*s1, char *s2)
{
	int				i;
	int				sizes1;
	int				sizes2;

	i = 0;
	sizes1 = ft_strlen(s1);
	sizes2 = ft_strlen(s2);
	if (sizes1 != sizes2)
		return (1);
	while(s1[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (1);
	}
	return (0);
}
void ft_search(char *str, t_num_word *tab)
{
	int i;

	i = 0;
	while(ft_strncmp(tab[i].number, str) != 0)
		i++;
	if(ft_strncmp(tab[i].number, str) == 0)
		ft_putstr(tab[i].words);
	else
		write(1, "Dictionary Error", 17);
}
	void	ft_putstr(char *str)
{
	while (*str)
		write(1, str ++, 1);
}
void	ft_double(char *str, t_num_word *tab)
{
	char *cpy;
	int i;
	
	cpy = ft_strdup(str);
	i = 0;
	while (cpy[++i])
		cpy[i] = '0';
	ft_search(cpy, tab);
	write(1," ",1);
	ft_search(&str[1], tab);
	free(cpy);
}
void ft_triple(char *str, t_num_word *tab)
{
	char *cpy;
	int i;
	char *cpy2;
	char *cpy3;

	cpy = ft_strdup(str);
	cpy2 = ft_strdup(str);
	i = 0;
	while (cpy[++i])
		cpy2[i] = '\0';
	ft_search(cpy2, tab);
	write(1," ",1);
	i = 0;
	while (cpy[++i])
		cpy[i] = '0';
	cpy[0] = '1';
	ft_search(cpy, tab);
	write(1," ",1);
	ft_double(&str[1], tab);
	free(cpy);
	free(cpy2);
}
void divide(t_num_word *tab,char *str)
{
	int	i;
	int size;
	
	i = 0;
	size = ft_strlen(str);
	if (size == 1)
		ft_search(str, tab);
	else if((size == 2 && str[0] == '1') || (size == 2 && str[1] == '0'))
		ft_search(str, tab);
	else if(size == 2)
		ft_double(str, tab);
	else if(size == 3)
		ft_triple(str, tab);
}
