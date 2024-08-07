/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:44:51 by lucmansa          #+#    #+#             */
/*   Updated: 2024/08/05 11:58:27 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

int	ft_strlen2(char **str, int tab_size)
{
	int	size;
	int	i;
	int	j;

	size = 0;
	i = 0;
	while (i < tab_size)
	{
		j = 0;
		while (str[i][j])
		{
			j++;
			size++;
		}
		i++;
	}
	return (size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		i;
	int		j;
	int		l;
	int		len;

	len = (ft_strlen2(strs, size) + (ft_strlen(sep) * size - 1));
	i = 0;
	l = 0;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			dest[l++] = strs[i][j++];
		j = 0;
		while (sep[j] && i != size -1)
			dest[l++] = sep[j++];
		i++;
	}
	dest[l] = 0;
	return (dest);
}

int	main(int argc, char **argv)
{
	char ** tab = malloc(sizeof(char *) * (argc - 2 + 10));
	int i = 1;
	while (++i < argc)
	{
		tab[i - 2] = argv[i];
		}
	char *x  =ft_strjoin(argc - 2, tab, argv[1]);
	printf("%s\n", x);
	free(x);
	return (0);
}
