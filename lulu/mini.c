/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:36:32 by tle-saut          #+#    #+#             */
/*   Updated: 2024/08/04 23:36:43 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				j;

	j = 0;
	i = 0;
	while (dest[j])
	{
		j++;
	}
	while (i < nb && src[i])
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int			i;
	char		*copy;

	i = 0;
	while (src[i])
		i++;
	copy = ft_calloc((i + 1) * sizeof(char));
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
	while (s1[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (1);
	}
	return (0);
}
void	ft_search(char *str, t_num_word *tab)
{
	int	i;

	if (str[0] == '0')
		return ;
	i = 0;
	while (ft_strncmp(tab[i].number, str) != 0)
		i++;
	if (ft_strncmp(tab[i].number, str) == 0)
		ft_putstr(tab[i].words);
	else
		write(1, "Dictionary Error", 17);
}

void ft_search_one(char str, t_num_word *tab)
{
	char	tmp[2];

	tmp[0] = str;
	tmp[1] = '\0';
	ft_search(tmp, tab);
}
char	*ft_conv_ten(char *str)
{
	int	i;

	str[0] = '1';
	i = 0;
	while (str[++i])
		str[i] = '0';
	return (str);
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
	
	if (str[0] == '0')
		ft_search(&str[1], tab);
	else if ((str[0] == '1') || (str[1] == '0'))
	{
		ft_search(str, tab);
		return ;
	}
	else
	{
		cpy = ft_strdup(str);
		i = 0;
		while (cpy[++i])
			cpy[i] = '0';
		ft_search(cpy, tab);
		write(1, " ", 1);
		ft_search(&str[1], tab);
		free(cpy);
	}
}
void ft_triple(char *str, t_num_word *tab)
{
	char *cpy;

	if (str[0] == '0')
		ft_double(&str[1], tab);
	else
	{
		cpy = ft_strdup(str);
		ft_search_one(str[0], tab);
		write(1, " ", 1);
		ft_search(ft_conv_ten(cpy), tab);
		if (str[1] == '0' && str[2] == '0')
			return ;
		write(1, " ", 1);
		ft_double(&str[1], tab);
		free(cpy);
	}
}
char **ft_multiply(char *str, int size)
{
	char	**t_n;
	int		i;
	int		last;

	i = 0;
	last = size / 3;
	t_n = ft_calloc(sizeof(char) * last + 1);
	while (i <= last)
	{
		t_n[i] = ft_calloc(sizeof(char) * 3);
		i++;
	}
	while (last > 0)
	{
		ft_strncat(t_n[last], &str[size - 3], 3);
		last--;
		size -= 3;
	}
	ft_strncat(t_n[last], &str[size - (ft_strlen(str) % 3)], ft_strlen(str) % 3);
	return (t_n);
}

char	*ft_ten_multiply(int size)
{
	int	i;
	int tot_size;
	char *ten;
	
	tot_size = size - (size % 3);
	ten = ft_calloc(sizeof(char) * tot_size);
	ten[0] = '1';
	i = 0;
	while (tot_size)
	{
		ten[++i] = '0';
		tot_size--;
	}
	return (ten);
}
void	ft_ultimate_search(char *str, t_num_word *tab)
{
	int	i;

	i = 0;
	while (ft_strncmp(tab[i].number, str) != 0)
		i++;
	if (ft_strncmp(tab[i].number, str) == 0)
		ft_putstr(tab[i].words);
	else
		write(1, "Dictionary Error", 17);
	free(str);
	write(1, " ", 1);
}

void	ft_fa_split(char **num_tab, char *str, int size, t_num_word *tab)
{
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	while (j < size)
	{
		if (!num_tab[i])
			return ;
		if (ft_strlen(num_tab[i]) == 1)
			ft_search(num_tab[i], tab);
		else if (ft_strlen(num_tab[i]) == 2)
			ft_double(num_tab[i], tab);
		else if (ft_strlen(num_tab[i]) == 3)
			ft_triple(num_tab[i], tab);
		j += 3;
		if (j < size && str[i] != '0')
		{
			write(1, " ", 1);
			ft_ultimate_search(ft_ten_multiply(size), tab);		
		}
		i++;
	}
}

void	divide(t_num_word *tab,char *str)
{
	int	size;
	int	i;

	size = ft_strlen(str);
	if (size == 1)
		ft_search(str, tab);
	else if (size == 2)
		ft_double(str, tab);
	else if (size == 3)
		ft_triple(str, tab);
	else if (size > 3)
		ft_fa_split(ft_multiply(str, size), str, size, tab);
	i = -1;
}

