/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:48:39 by lucmansa          #+#    #+#             */
/*   Updated: 2024/08/03 21:56:46 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putstr(const char *str)
{
	while (*str)
		write(1, str++, 1);
}

int ft_strlen(const char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return (len);
}

int ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return *(unsigned char *)s1 - *(unsigned char *)s2;
}

char *ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = '\0';
	return dest;
}