/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:39:19 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/23 11:13:55 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
void	swap(int *nbr1, int *nbr2)
{
	int	temp;

	temp = *nbr1;
	*nbr1 = *nbr2;
	*nbr2 = temp;
}

void	ft_rev_in_tab(int *tab, int size)
{
	int	swaps;
	int	i;

	i = 0;
	swaps = size / 2;
	while (swaps--)
		swap(&(tab[i++]), &(tab[--size]));
}
/*
int main(void)
{
	int	t[10];

	for	(int i=0; i<10; i++)
		t[i] = rand()%101;

	printf("Before ");
	for (int i=0; i<10; i++)
		printf("%d", t[i]);
	printf("\n");

	ft_rev_in_tab(t, sizeof(t)/sizeof(t[0]));

	printf("After ");
	for (int i=0; i<10; i++)
		printf("%d", t[i]);
	printf("\n");
}
*/
