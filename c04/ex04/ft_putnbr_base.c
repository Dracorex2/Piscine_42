/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:56:12 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/25 09:31:52 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	if (!str)
		return(0);
	while (str[size] != '\0')
		size++;
	return (size);
}


int	base_check(char *str)
{
	int i;
	int j;

	while (str[++i])
	{
		if (str[i] == 0 || str[i] == 1|| str[i] == '+' || str[i] == '-')
			return (0);
		j = -1;
		while (str[++j])
			if (str[i] == str[j])
				return (0);
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void ft_putnbr_base(int nbr, char *base)
{
    long nb;
    int b;

    b = ft_strlen(base);
	nb = nbr;
	if (base_check(base) == 0)
		write(1, "error", 5);
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb *= -1;
		}
		if (nb > b)
		{
			ft_putnbr_base(nb / b, base);
			ft_putnbr_base(nb % b, base);
		}
		else
			ft_putchar(base[nb]);
	}
}


int	main(int argc, char **argv)
{
	ft_putnbr_base(atoi(argv[1]), "0123456789ABCDEF");
}