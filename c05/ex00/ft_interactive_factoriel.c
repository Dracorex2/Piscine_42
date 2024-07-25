/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interactive_factoriel.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:28:36 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/25 09:45:57 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int ft_iterative_factorial(int nb)
{
	int	i;

	i = nb;
	if (nb == 0)
		return(0);
	while (--i)
		nb *= i;
	return (nb);
}

int	main(void)
{
	printf("%d", ft_iterative_factorial(0));
}