/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:06:12 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/26 08:51:19 by lucmansa         ###   ########.fr       */
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

void    *sort(char **sort, int size)
{
    int i;
    int j;

    i = -1;
    j = -1;
    while (++i < size -1) 
    {
        while (++j < size - i - 1) 
        {
            if (sort[j] > sort[j + 1])
            {
                ft_swap(&sort[j], &sort[j + 1]);
            }
        }
    }
}

/*
int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}
*/
int main (int argc, char **argv)
{
    sort(argv, argc);
    printf("%i", argv);
}