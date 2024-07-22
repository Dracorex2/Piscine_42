/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:17:25 by gaducass          #+#    #+#             */
/*   Updated: 2024/07/20 14:27:53 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush03(int x, int y)
{
	int	i;
	int	j;

	j = y;
	while (j > 0)
	{
		i = x;
		while (i > 0)
		{
			if ((j == y || j == 1) && i == x)
				ft_putchar('A');
			else if ((j == y || j == 1) && i == 1)
				ft_putchar('C');
			else if (i == x || j == y || j == 1 || i == 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			i--;
		}
		ft_putchar('\n');
		j--;
	}
}
