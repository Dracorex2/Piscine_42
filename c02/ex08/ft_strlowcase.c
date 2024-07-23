/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:08:35 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/23 15:38:59 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
char	*ft_strlowcase(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	return (str);
}
/*
int	main(void)
{
	char	str[] = "abHdg456";

	printf("ft returns %s\n", ft_strupcase(str));
}
*/
