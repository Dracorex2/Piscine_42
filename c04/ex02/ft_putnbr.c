/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:44:54 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/23 19:44:02 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int i;

	i = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
		
	while (nb > 10)
	{
		
		ft_putchar((nb % 10) + 48);
		nb = nb / 10;
	}
	if (nb >= 0 && nb < 10)
		ft_putchar(nb + 48);

}


int	main(void)
{
	ft_putnbr(442);
}