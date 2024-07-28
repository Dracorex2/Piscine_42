/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:08:34 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/28 23:12:57 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_iterative_power(int nb, int power)
{
    if (power < 0)
        return (0);
    if (power == 0)
        return (1);
    while (--power)
        nb *= nb;
    return (nb);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%i", ft_iterative_power(56, 0));
}
*/