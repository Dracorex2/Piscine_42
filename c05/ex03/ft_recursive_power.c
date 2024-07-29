/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:51:46 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/29 09:13:10 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int ft_recursive_power(int nb, int power)
{
	int	sign;

	sign = 1;
	if (nb < 0)
	{
		sign *= -1;
		nb *= -1;
	}
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1) * sign);
}
/*
int	main(void)
{
	printf("%i", ft_recursive_power(-5, 2));
}
*/