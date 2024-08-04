/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:00:09 by lucmansa          #+#    #+#             */
/*   Updated: 2024/08/04 15:18:51 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*

read_dict
-> split_lines
-> for each parse line 
	-> return tab
-> separate every 3 number (123456 -> 123 Mile 456 Rien)

*/


#include "header.h"

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

void parse2(int j, int *i, char *str, t_num_word *tab)
{
	int	k;

	k = 0;
	tab[j].number = malloc(0x100);
	tab[j].words = malloc(0x100);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		tab[j].number[k] = str[(*i)++];
		k++;
	}
	while (str[*i] == ' ' || str[*i] == ':')
		(*i)++;
	k = 0;
	while (str[*i] != '\n' && str[*i] != '\0')
	{
		while (str[*i] == ' ' && str[*i + 1] == ' ')
			(*i)++;
		tab[j].words[k] = str[(*i)++];
		k++;
	}
}


t_num_word *parse(void)
{
	char *str;
	t_num_word *tab;
	int	i;
	int	j;
	int	k;

	str = get_dict();
	tab = malloc(sizeof(t_num_word) * (ft_strlen(str) + 1));
	i = 0;
	j = 0;
	while (str[i])
	{
		parse2(j, &i, str, tab);
		if (!str[i])
			break ;
		j++;
		i++;
	}
	free(str);
	return (tab);
}

int	check_exist(void)
{
	int		fd;
	fd = open(dictionary, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

char *get_dict(void)
{
	int	fd;
	char *tab;
	int	size;
 
 	size = dict_size();
 	tab = malloc(sizeof(char) * (size + 1));
	fd = open(dictionary, O_RDONLY);
	read(fd, tab, size);
	tab[size] = '\0';
	close(fd);
	return (tab);
}

int	dict_size(void)
{
	int		fd;
	int		size;
	char	buffer;

	size = 0;
	fd = open(dictionary, O_RDONLY);
	while (read(fd, &buffer, 1))
		size++;
	close(fd);
	return (size);
}


int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		parse();
	}
	else if (argc == 3)
	{
		return (0);
	}
	else
		write(2, "error", 5);
}
