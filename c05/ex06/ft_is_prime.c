/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:30:15 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/29 20:50:48 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 3;
	if (nb == 2)
		return (1);
	if (nb < 2 || nb % 2 == 0)
		return (0);
	while (i < nb)
	{
		if ((nb % i) == 0)
			return (0);
		i += 2;
	}
	return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%i", ft_is_prime(2147483647));
}
*/