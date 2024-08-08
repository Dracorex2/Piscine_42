/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:37:24 by lucmansa          #+#    #+#             */
/*   Updated: 2024/08/08 10:24:16 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
	{
		if (c == charset[i])
			return (1);
	}
	return (0);
}

char	*ft_strdup(char *src, char *charset)
{
	int		len;
	char	*res;
	int		i;

	len = 0;
	while (src[len])
		len++;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	i = -1;
	while (src[++i] != '\0' && !is_charset(src[i], charset))
		res[i] = src[i];
	res[i] = '\0';
	return (res);
}

int	count(char *str, char *charset)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (is_charset(str[i], charset))
			i++;
		if (!str[i])
			return (word);
		word++;
		while (!is_charset(str[i], charset) && str[i] != 0)
			i++;
	}
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		len;
	int		j;

	tab = malloc((count(str, charset) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	len = (count(str, charset) - 1);
	j = 0;
	i = 0;
	while (i <= len)
	{
		while (is_charset(str[j], charset))
			j++;
		tab[i] = ft_strdup(&str[j], charset);
		while (!is_charset(str[j], charset) && str[j] != 0)
			j++;
		while (is_charset(str[j], charset))
			j++;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
/*
#include <stdio.h>
int	main(void)
{
	char 	c[] = "jasr";
	char 	charset[] = " ";
	char 	**res;
	int		i;
	"iodjrt" + 30
	i = -1;
	res = ft_split(c, charset);
	while (res[++i] != NULL)
		printf("%s\n", res[i]);

}
*/