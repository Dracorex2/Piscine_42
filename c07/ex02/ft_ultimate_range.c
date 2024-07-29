/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:49:10 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/29 18:05:21 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
    int i;
    int len;

    if (min >= max)
        return 0;
    len = max - min;
    i = 0;
    *range = malloc(sizeof(int) * len);
    if (!*range)
		return (0);
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
    int i; 

    i = -1;
	ft_ultimate_range(&res, 1, 100);
    while (res[++i] != 100)
	    printf("%i\n", res[i]);
    free(res);
	return (0);
}
*/
