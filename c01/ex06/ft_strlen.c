/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:44:54 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/21 17:02:22 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	ft_strlen(char *str)
{
	int	size;

	while (str[size] != '\0')
		size++;
	return (size);
}

int	main(void)
{
	char *c;
	c = "hello";
	printf("%d character", ft_strlen(c));
}

