/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:49:10 by lucmansa          #+#    #+#             */
/*   Updated: 2024/08/08 12:04:55 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	len;

	if (min > max)
	{
		*range = NULL;
		return (0);
	}
	len = max - min;
	i = 0;
	*range = malloc(sizeof(int) * len);
	if (range == NULL)
		return (-1);
	while (min < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (len);
}
/*
#include <stdio.h>
int	main(void)
{
	int	*res;
	int	i; 
	int	size;

	i = 0;
	size = ft_ultimate_range(&res, 0, 10);
	while (i < size)
		printf("%i\n", res[i++]);
	free(res);
	return (0);
}
*/