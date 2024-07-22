/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:52:37 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/21 09:44:42 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
void	main(void)
{
	int nbr1;
	int nbr2;
	int quotient;
	int remainder;

	nbr1 = 15;
	nbr2 = 6;
	ft_div_mod(nbr1, nbr2, &quotient, &remainder);
	printf("The quotient is %d", quotient);
	printf("\nThe remainder is %d", remainder);
}
*/
