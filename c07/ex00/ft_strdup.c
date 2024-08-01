/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:28:51 by lucmansa          #+#    #+#             */
/*   Updated: 2024/08/01 15:54:33 by lucmansa         ###   ########.fr       */
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

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i] != '\0')
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int	len;
	char * res;

	len = ft_strlen(src);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res = ft_strcpy(res, src);
	return (res);
}
/*
int	main(void)
{
	char	*res;

	res = ft_strdup("wesh");
	printf("%p ; %s\n", res, res);
	free(res);
	return (0);
}
*/