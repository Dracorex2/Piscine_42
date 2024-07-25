/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:06:12 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/25 20:13:02 by lucmansa         ###   ########.fr       */
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

char    *sort(char **sort, int size)
{
    int i;
    int j;

    i = -1;
    while (++i < size -1) 
    {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                ft_wap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void	ft_swap(char **a, char **b)
{
	char	*i;

	i = *a;
	*a = *b;
	*b = i;
}

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

int main (int argc, char **argv)
{
    int i;

    i = argc;
    while (--i > 0)
    {
        write(1, argv[i], ft_strlen(argv[i]));
        write(1, "\n", 1);
    }
}

[5, ]