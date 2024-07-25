/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itersctive_power.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:08:34 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/25 11:00:23 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int ft_iterative_power(int nb, int power)
{
    if (power == 0)
        return (1);
    while (--power)
        nb *= nb;
    return (nb);
}

int	main(void)
{
	printf("%i", ft_iterative_power(56, 0));
}