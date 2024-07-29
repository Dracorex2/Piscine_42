/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:44:51 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/29 17:31:23 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int	i;
	int	j;
	int l;

	i = 0;
	l = 0;
	dest = malloc(sizeof(char) * (10000 + 1));
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

int main(int argc, char **argv)
{
	char	*sep;
	char	*tab[4];

	sep = " tres ";
	tab[0] = "comment";
	tab[1] = "franche";
	tab[2] = "le c07";
	tab[3] = "deviens";
	char *test = ft_strjoin(4, tab, sep);
	printf("%s", test);
	return (0);
}