/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:52:33 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/28 11:45:26 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_strlen(char *str)
{
	unsigned int	size;

	size = -1;
	while (str[++size] != '\0')
		;
	return (size);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	size;

	i = -1;
	size = ft_strlen(to_find);
	if (to_find[0] == 0)
		return (&str[0]);
	while (str[++i])
	{
		if (str[i] == to_find[0])
		{
			if (ft_strncmp(&str[i], &to_find[0], size) == 0)
				return (&str[i]);
		}
	}
	return (0);
}
/*
#include <string.h>
int	main(void)
{
	char d[] = "Jse_sui_vraiment_tylerere_sss_suiw";
	char c[] = "";

	printf("%s", ft_strstr(d, c));
}
*/