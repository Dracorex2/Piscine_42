/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:15:48 by lucmansa          #+#    #+#             */
/*   Updated: 2024/08/07 21:50:35 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	base_check(char *str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
		i++;
	if (i < 2)
		return (0);
	i = -1;
	while (str[++i])
	{

		if ((str[i] == '+' || str[i] == '-' || str[i] == ' ')
			|| (str[i] >= '\t' && str[i] <= '\r'))
			return (0);
		j = i;
		while (str[++j])
			if (str[i] == str[j])
				return (0);
	}
	return (i);
}

int	ft_comp(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (i);
	return (-1);
}

void	ft_putnbr_base(int nbr, char *base, char *res, int *i)
{
	int long	nbl;
	int			b;

	b = base_check(base);
	nbl = nbr;
	if (nbl < 0)
	{
		res[++(*i)] = '-';
		nbl *= -1;
	}
	if (nbl >= b)
	{
		ft_putnbr_base(nbl / b, base, res, i);
		ft_putnbr_base(nbl % b, base, res, i);
	}
	else
		res[++(*i)] = base[nbl];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	int		i;
	int		sign;
	char	*res;

	res = malloc(sizeof(char) * 36);
	if (base_check(base_from) < 2 || base_check(base_to) < 2)
		return (0);
	nb = 0;
	i = 0;
	sign = 1;
	while (nbr[i] == ' ' || (nbr[i] >= '\t' && nbr[i] <= '\r'))
		i++;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_comp(nbr[i], base_from) != -1)
		nb = nb * base_check(base_from) + (ft_comp(nbr[i++], base_from));
	i = -1;
	ft_putnbr_base((nb * sign), base_to, res, &i);
	res[++i] = 0;
	return (res);
}
/*
int main()
{
	char    str[] = "	-2147483648";
	char    *res;

	res = ft_convert_base(str, "0123456789", "01");
	printf("%s", res);
}
*/