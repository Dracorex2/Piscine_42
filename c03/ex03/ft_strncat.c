/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:20:58 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/28 10:19:14 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	unsigned int	size;

	size = -1;
	while (str[++size] != '\0')
		;
	return (size);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				size;
	unsigned int	i;

	i = 0;
	size = ft_strlen(dest);
	while (i < nb && src[i] != 0)
	{
		dest[size + i] = src[i];
		i++;
	}
	dest[size + i] = 0;
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
	char c[] = "ma_poule";
	char d[] = "wesh_wesh_";

	printf("%s", ft_strncat(d, c, 2));
}
*/