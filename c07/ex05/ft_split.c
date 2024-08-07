/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:37:24 by lucmansa          #+#    #+#             */
/*   Updated: 2024/08/07 10:39:16 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	if (!str)
		return (0);
	while (str[size] != '\0')
		size++;
	return (size);
}

char **ft_split(char *str, char *charset)
{

}