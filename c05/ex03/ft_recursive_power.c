/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:51:46 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/25 14:07:59 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int ft_iterative_power(int nb, int power)
{

	if (power == 0)
		return (1);
	return (nb * ft_iterative_power(nb, power - 1));
}

int	main(void)
{
	printf("%i", ft_iterative_power(0, 5));
}