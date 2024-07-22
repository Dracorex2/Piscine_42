/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:02:44 by gaducass          #+#    #+#             */
/*   Updated: 2024/07/20 17:19:24 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush00(int x, int y);
void	rush01(int x, int y);
void	rush02(int x, int y);
void	rush03(int x, int y);
void	rush04(int x, int y);

int	ft_atoi(char *str)
{
	int	tot;
	int	i;
	int	sign;

	tot = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		tot = tot * 10 + (str[i++] - '0');
	return (tot * sign);
}

void	ft_rush(int x, int y, int choice)
{
	if (x < 1 || y < 1)
	{
		write(1, "Invalid number\n", 15);
		return ;
	}
			if (choice < 0 || choice > 4)
				write(1, "Invalid rush version\n", 21);
	else if (choice == 0)
		rush00(x, y);
	else if (choice == 1)
		rush01(x, y);
	else if (choice == 2)
		rush02(x, y);
	else if (choice == 3)
		rush03(x, y);
	else if (choice == 4)
		rush04(x, y);
}

int	main(int argc, char **argv)
{
	if (argc == 4)
		ft_rush(ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]));
	else if (argc == 3)
		ft_rush(ft_atoi(argv[1]), ft_atoi(argv[2]), 2);
	else if (argc == 2)
		write(1, "Missing number\n", 15);
	else
		rush02(5, 5);
	return (0);
}
