/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:42:31 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/18 09:01:23 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	write_n(char v[])
{
	if (v[0] == '7' && v[1] == '8' && v[2] == '9')
	{
		write(1, v, 3);
		write(1, "\n", 1);
	}
	else
		write(1, v, 13);
}

void	ft_print_combn(int n)
{
	char	v[13];
	int i;
	i = 0;
	int i2;

	v[0] = 0;
	v[11] = ',';
	v[12] = ' ';
	if (n < 10);
	{
		while (n > 0)
		{
			i2 = i+1;
			v[i2] = v[i] + 1;
			write_n(v+48);
			n--;
		}

 	}

}

int	main(void)
{
	ft_print_combn(2);
}
