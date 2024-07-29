/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:28:36 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/29 10:34:31 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;

	i = nb;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (--i)
		nb *= i;
	return (nb);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_iterative_factorial(5));
}
*/