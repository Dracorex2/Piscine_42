/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:51:01 by cguinot           #+#    #+#             */
/*   Updated: 2024/08/03 21:56:46 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 50
}
						char *buffer, int i);
int					parse_word(t_num_word dict[], int index,
						char *buffer, int i);
void				ft_putstr(const char *str);
int					ft_strlen(const char *str);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
void				*ft_memmove(void *dest, const void *src, size_t n);
int					ft_snprintf(char *str, size_t size, const char *format,
						unsigned long long value);
unsigned long long	ft_strtoull(const char *str, char **endptr, int base);
void				number_to_words(t_num_word dict[], int dict_size,
						const char *num_str);

void	ft_putstr(const char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n;
		s += n;
		while (n--)
			*(--d) = *(--s);
	}
	return (dest);
}

int	ft_ulltoa(unsigned long long value, char *str, int base)
{
	char				*ptr;
	char				*ptr1;
	char				tmp_char;
	unsigned long long	tmp_value;

	ptr = str;
	ptr1 = str;
	if (value == 0)
		*ptr++ = '0';
	while (value)
	{
		tmp_value = value % base;
		*ptr++ = "0123456789"[tmp_value];
		value /= base;
	}
	*ptr-- = '\0';
	while (ptr1 < ptr)
	{
		tmp_char = *ptr;
		*ptr-- = *ptr1;
		*ptr1++ = tmp_char;
	}
	return (ptr - str + 1);
}

int	ft_snprintf(char *str, size_t size, const char *format,
		unsigned long long value)
{
	if (format[0] == '%' && format[1] == 'l'
		&& format[2] == 'l' && format[3] == 'u')
	{
		return (ft_ulltoa(value, str, 10));
	}
	return (0);
}

unsigned long long	ft_strtoull(const char *str, char **endptr, int base)
{
	unsigned long long	result;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * base + (*str - '0');
		str++;
	}
	if (endptr)
		*endptr = (char *)str;
	return (result);
}

int	load_dictionary(t_num_word dict[], const char *filename)
{
	int		fd;
	int		bytes_read;
	int		index;
	char	buffer[BUFFER_SIZE];

	index = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	close(fd);
	buffer[bytes_read] = '\0';
	index = parse_dictionary(dict, buffer, bytes_read);
	return (index);
}

int	parse_dictionary(t_num_word dict[], char *buffer, int bytes_read)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (i < bytes_read)
	{
		i = parse_number(dict, index, buffer, i);
		i = parse_word(dict, index, buffer, i);
		index++;
	}
	return (index);
}

int	parse_number(t_num_word dict[], int index, char *buffer, int i)
{
	char	*ptr;

	ptr = dict[index].number;
	while (buffer[i] != ':' && buffer[i] != '\0')
		*ptr++ = buffer[i++];
	*ptr = '\0';
	return (i + 2);
}

int	parse_word(t_num_word dict[], int index, char *buffer, int i)
{
	char	*ptr;

	ptr = dict[index].word;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		*ptr++ = buffer[i++];
	*ptr = '\0';
	return (i + 1);
}

const char	*find_word(t_num_word dict[], int dict_size, const char *num_str)
{
	int	i;

	i = 0;
	while (i < dict_size)
	{
		if (ft_strcmp(dict[i].number, num_str) == 0)
			return (dict[i].word);
		i++;
	}
	return (NULL);
}

void	str_divmod(const char *num_str, const char *divisor_str,
		char *quotient_str, char *remainder_str)
{
	unsigned long long	divisor;
	unsigned long long	remainder;
	int					i;
	int					len;

	divisor = ft_strtoull(divisor_str, NULL, 10);
	remainder = 0;
	len = ft_strlen(num_str);
	i = 0;
	while (i < len)
	{
		remainder = remainder * 10 + (num_str[i] - '0');
		quotient_str[i] = (remainder / divisor) + '0';
		remainder %= divisor;
		i++;
	}
	quotient_str[i] = '\0';
	i = 0;
	while (quotient_str[i] == '0' && quotient_str[i + 1] != '\0')
		i++;
	ft_memmove(quotient_str, quotient_str + i, ft_strlen(quotient_str) - i + 1);
	ft_snprintf(remainder_str, 40, "%llu", remainder);
}

void	handle_three_digit(t_num_word dict[], int dict_size,
			const char *num_str)
{
	char	hundreds[2];

	hundreds[0] = num_str[0];
	hundreds[1] = '\0';
	ft_putstr(find_word(dict, dict_size, hundreds));
	ft_putstr(" hundred");
	if (num_str[1] != '0' || num_str[2] != '0')
	{
		ft_putstr(" ");
		number_to_words(dict, dict_size, &num_str[1]);
	}
}

void	handle_two_digit(t_num_word dict[], int dict_size, const char *num_str)
{
	char	tens[3];
	char	ones[2];

	if (num_str[0] == '1' || num_str[1] == '0')
	{
		ft_putstr(find_word(dict, dict_size, num_str));
	}
	else
	{
		tens[0] = num_str[0];
		tens[1] = '0';
		tens[2] = '\0';
		ft_putstr(find_word(dict, dict_size, tens));
		if (num_str[1] != '0')
		{
			ft_putstr("-");
			ones[0] = num_str[1];
			ones[1] = '\0';
			ft_putstr(find_word(dict, dict_size, ones));
		}
	}
}

void	process_small_number(t_num_word dict[], int dict_size,
			const char *num_str)
{
	const char	*word;
	int			len;

	word = find_word(dict, dict_size, num_str);
	len = ft_strlen(num_str);
	if (word)
		ft_putstr(word);
	else if (len == 3)
		handle_three_digit(dict, dict_size, num_str);
	else if (len == 2)
		handle_two_digit(dict, dict_size, num_str);
	else if (len == 1)
		ft_putstr(find_word(dict, dict_size, num_str));
}

const char	*get_large_base(int len)
{
	if (len > 36)
		return ("1000000000000000000000000000000000000");
	if (len > 33)
		return ("1000000000000000000000000000000000");
	if (len > 30)
		return ("1000000000000000000000000000000");
	if (len > 27)
		return ("1000000000000000000000000000");
	if (len > 24)
		return ("1000000000000000000000000");
	if (len > 21)
		return ("1000000000000000000000");
	if (len > 18)
		return ("1000000000000000000");
	if (len > 15)
		return ("1000000000000000");
	if (len > 12)
		return ("1000000000000");
	if (len > 9)
		return ("1000000000");
	if (len > 6)
		return ("1000000");
	return ("1000");
}

void	process_large_number(t_num_word dict[], int dict_size,
			const char *num_str)
{
	char		quotient[40];
	char		remainder[40];
	const char	*base;
	int			i;

	i = 0;
	while (i < 40)
	{
		quotient[i] = 0;
		remainder[i] = 0;
		i++;
	}
	base = get_large_base(ft_strlen(num_str));
	str_divmod(num_str, base, quotient, remainder);
	number_to_words(dict, dict_size, quotient);
	ft_putstr(" ");
	ft_putstr(find_word(dict, dict_size, base));
	if (ft_strcmp(remainder, "0") != 0)
	{
		ft_putstr(" ");
		number_to_words(dict, dict_size, remainder);
	}
}

void	number_to_words(t_num_word dict[], int dict_size, const char *num_str)
{
	int	len;

	if (ft_strcmp(num_str, "0") == 0)
	{
		ft_putstr("zero");
		return ;
	}
	len = ft_strlen(num_str);
	if (len > 3)
		process_large_number(dict, dict_size, num_str);
	else
		process_small_number(dict, dict_size, num_str);
}

void	handle_error(const char *message, t_num_word *dict)
{
	ft_putstr(message);
	if (dict)
		free(dict);
	exit(1);
}

void	init_number_str(char *dest, const char *src, size_t size)
{
	ft_strncpy(dest, src, size - 1);
	dest[size - 1] = '\0';
}

t_num_word	*init_dictionary(int *dict_size)
{
	t_num_word	*dict;

	dict = (t_num_word *)malloc(sizeof(t_num_word) * MAX_DICTIONARY_SIZE);
	if (!dict)
		handle_error("Memory allocation failed.\n", NULL);
	*dict_size = load_dictionary(dict, "dictionary.txt");
	if (*dict_size == -1)
		handle_error("Error: Could not load dictionary.\n", dict);
	return (dict);
}

int	main(int argc, char **argv)
{
	t_num_word	*dict;
	char		number_str[40];
	int			dict_size;

	if (argc != 2)
		handle_error("Usage: ./aout [number]\n", NULL);
	init_number_str(number_str, argv[1], sizeof(number_str));
	dict = init_dictionary(&dict_size);
	number_to_words(dict, dict_size, number_str);
	ft_putstr("\n");
	free(dict);
	return (0);
}
za