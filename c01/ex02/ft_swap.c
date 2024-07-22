/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:46:04 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/21 09:44:21 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
void	ft_swap(int *a, int *b)
{
	int	i;

	i = *a;
	*a = *b;
	*b = i;
}
/*
void	main(void)
{
	int ent1;
	int ent2;

	ent1 = 100;
	ent2 = 50;
	printf("ent 1 = %d", ent1);
	printf("\nent 2 = %d", ent2);
	ft_swap(&ent1, &ent2);
	printf("\nent 1 = %d", ent1);
	printf("\nent 2 = %d", ent2);
}
*/
