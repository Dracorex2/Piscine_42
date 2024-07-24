/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:07:18 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/24 14:21:22 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int ft_atoi(char *str)
{
	int	nbr;
	int	i;
	int	sign;

    nbr = 0;
	i = 0;
	sign = 1;

    while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' ||
		    str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
	{
		i++;
	}
    while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + (str[i++] - '0');
	return (nbr * sign);
}

int	main(int argc, char **argv)
{
    printf("%d", ft_atoi(argv[1]));
}

