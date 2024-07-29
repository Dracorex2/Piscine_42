/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:06:12 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/29 14:06:52 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

void	ft_swap(char **a, char **b)
{
	char	*i;

	i = *a;
	*a = *b;
	*b = i;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	sort(char **sort, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++j < size -1)
	{
		i = 0;
		while (++i < size - 1)
			if (ft_strcmp(sort[i], sort[i + 1]) >= 0)
				ft_swap(&sort[i], &sort[i + 1]);
	}
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	int	i;

	if (argc > 1)
	{
		sort(argv, argc);
    	i = 0;
    	while (++i < argc)
    	{
        	write(1, argv[i], ft_strlen(argv[i]));
        	write(1, "\n", 1);
    	}
	}
	return (0);
}