/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:15:48 by lucmansa          #+#    #+#             */
/*   Updated: 2024/08/07 16:10:38 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	if (!str)
		return (0);
	while (str[size] != '\0')
		size++;
	return (size);
}

int	base_check(char *str)
{
	int	i;
	int	j;

	i = -1;
	if (ft_strlen(str) == 0 || ft_strlen(str) == 1)
		return (0);
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
	return (1);
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

	b = ft_strlen(base);
	nbl = nbr;
	if (base_check(base) == 0)
		return ;
	else
	{
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
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	int		i;
	int		sign;
	char	*res;

	res = malloc(sizeof(char) * 36);
	if (!base_check(base_from) || !base_check(base_to))
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
		nb = nb * ft_strlen(base_from) + (ft_comp(nbr[i++], base_from));
	i = -1;
	ft_putnbr_base((nb * sign), base_to, res, &i);
	res[++i] = 0;
	return (res);
}
/*
int main()
{
	char    str[] = "42";
	char    *res;

	res = ft_convert_base(str, "0123456789", "0123456789abcdef");
	printf("%s", res);
}
*/