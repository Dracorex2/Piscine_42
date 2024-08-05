# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/04 17:35:27 by tle-saut          #+#    #+#              #
#    Updated: 2024/08/04 18:07:22 by tle-saut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME: rush

rush: main.o mini.o
	cc -Wall -Wextra -Werror -o rush main.o mini.o

main.o: main.c
	cc -Wall -Werror -Wextra -o main.c

mini.o: mini.c
	cc -Wall -Werror -Wextra -o mini.c

clean:
	rm -f *.o
fclean:
	rm -f rush
