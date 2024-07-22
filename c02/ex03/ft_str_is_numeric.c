/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:08:35 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/21 14:27:34 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != 0)
		if (!((str[i] >= '0' && str[i] <= '9')))
			return (0);
	return (1);
}


int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = "abHdg456";
	str2 = "";
	printf("ft returns %i for str %s\n", ft_str_is_alpha(str1), str1);
	printf("ft returns %i for str %s\n", ft_str_is_alpha(str2), str2);
}
