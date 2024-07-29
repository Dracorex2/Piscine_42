/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:08:34 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/29 11:18:32 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (++i < power)
		nb = nb * nbr;
	return (nb);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%i", ft_iterative_power(-2, 3));
}
*/