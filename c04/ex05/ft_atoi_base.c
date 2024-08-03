/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:14:48 by lucmansa          #+#    #+#             */
/*   Updated: 2024/08/02 10:25:08 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
int ft_comp(char c, char *base)
{
	int i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (i);
	return (-1);
}


int ft_atoi_base(char *str, char *base)
{
	int	nbr;
	int	i;
	int	sign;

	if (base_check(base) == 0)
		return (0);
	nbr = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_comp(str[i], base) != -1)
		nbr = nbr * ft_strlen(base) + (ft_comp(str[i++], base));
	return (nbr * sign);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc < 3)
		return (1);
	printf("%d", ft_atoi_base(argv[1], "abcdef\n"));
}