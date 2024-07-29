/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:08:34 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/29 09:28:47 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_iterative_power(int nb, int power)
{
	int	sign;

	sign = 1;
	if (power < 0)
		return (0);
	if (nb < 0)
	 {
		sign *= -1;
		nb *= -1;
	 }
	if (power == 0)
		return (1);
	while (--power > 1)
		nb *= nb;
	return (nb * sign);
}

#include <stdio.h>
int	main(void)
{
	printf("%i", ft_iterative_power(-5, 4));
}
