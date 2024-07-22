/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:12:32 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/22 15:18:22 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	unsigned int	size;

	size = -1;
	while (str[++size] != '\0')
		;
	return (size);
}

char *ft_strcat(char *dest, char *src)
{
	int size;
	int i;

	i = -1;
	size = ft_strlen(dest);
	while (src[++i])
		dest[size + i] = src[i];
	dest[size + i] = 0;
	return (dest);
}



int	main(void)
{
	char c[] = "llo";
	char d[] = "yo";

	printf("%s", ft_strcat(d, c));
}