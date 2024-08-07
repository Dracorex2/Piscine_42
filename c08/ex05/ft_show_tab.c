/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:59:41 by lucmansa          #+#    #+#             */
/*   Updated: 2024/08/07 10:39:06 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != 0)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putnbr(int nb)
{
	long	nbr;
	char	c;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putstr("-");
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
	}
	c = (nbr % 10) + 48;
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putstr("\n");
		ft_putnbr(par[i].size);
		ft_putstr("\n");
		ft_putstr(par[i].copy);
		ft_putstr("\n");
		i++;
	}
}
/*
extern struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

#include <stdlib.h>

int main(int argc, char **argv) 
{
	int	i;

	t_stock_str *tab = ft_strs_to_tab(argc, argv);
	ft_show_tab(tab);
	i = 0;
	while (tab[i].str != NULL)
	{
		free(tab[i].copy);
		i++;
	}
	free(tab);
	return (0);
}
*/