/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:09:21 by lucmansa          #+#    #+#             */
/*   Updated: 2024/08/08 12:04:55 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*res;
	int	i;

	if (min >= max)
	{
		res = 0;
		return (0);
	}
	i = 0;
	res = malloc(sizeof(int) * (max - min));
	if (!res)
		return (0);
	while (min < max)
	{
		res[i] = min;
		min++;
		i++;
	}
	return (res);
}
/*
#include <stdio.h>
int	main(void)
{
	int	*res;
	int i; 


	i = 0;
	res = ft_range(-100, 100);
	while (res[i] != 100)
		printf("%i\n", res[i++]);
	free(res);
	return (0);
}
*/