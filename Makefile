# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liemi <liemi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/19 20:16:53 by liemi             #+#    #+#              #
#    Updated: 2025/11/13 23:39:14 by liemi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

LIBFT	= libft/libft.a

SOURCES	= client.c server.c
OBJECTS	= $(SOURCES:.c=.o)

BSOURCES = client_bonus.c server_bonus.c
BOBJECTS = $(BSOURCES:.c=.o)

all: server client

bonus: $(BOBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) server_bonus.o $(LIBFT) -o server
	$(CC) $(CFLAGS) client_bonus.o $(LIBFT) -o client

server: server.o $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

client: client.o $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

clean:
	rm -f $(OBJECTS) $(BOBJECTS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f server client
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all bonus clean fclean re libft
