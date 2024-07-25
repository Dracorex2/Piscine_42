/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:17:03 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/25 16:29:08 by lucmansa         ###   ########.fr       */
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

int main (int argc, char **argv)
{
    int i;

    i = argc;
    while (i > 0)
   {
        write(1, "\n", 1);
        write(1, argv[i], ft_strlen(argv[i - 1]));
        i--;
    }

}