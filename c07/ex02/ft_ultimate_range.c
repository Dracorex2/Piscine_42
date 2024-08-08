/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:49:10 by lucmansa          #+#    #+#             */
/*   Updated: 2024/08/08 10:28:29 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
    int i;
    int len;

    if (min < max)
    {
            return (0);
        len = max - min;
        i = 0;
        *range = malloc(sizeof(int) * len);
        if (range == NULL)
            return (0);
        while (min < max)
        {
            (*range)[i] = min;
            min++;
            i++;
        }
        return (len);
    }
    return (0);
}

#include <stdio.h>
int	main(void)
{
	int	*res;
    int i; 

    i = -1;
	ft_ultimate_range(&res, 2, 0);
    while (res[++i] != 100)
	    printf("%i\n", res[i]);
    free(res);
	return (0);
}
