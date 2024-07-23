/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_ft.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:48:41 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/23 11:13:02 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
void	ft_ultimate_div_ft(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}
/*
void main(void)
{
	int nbr1;
	int nbr2;
	nbr1 = 15;
	nbr2 = 6;
	ft_ultimate_div_ft(&nbr1, &nbr2);
	printf("The quotient is %d", nbr1);
	printf("\nThe remainder is %d", nbr2);
}
*/
