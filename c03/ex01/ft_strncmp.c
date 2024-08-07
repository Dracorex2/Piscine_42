/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:46:24 by lucmansa          #+#    #+#             */
/*   Updated: 2024/07/28 10:19:13 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}
/*
int main(void)
{
	char    str1[] = "abcc";
	char    str2[] = "accd";
	unsigned int i;

	i = 1;
	printf("%d", ft_strncmp(str1, str2, i));
}
*/