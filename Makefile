# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/24 15:54:46 by asaouab           #+#    #+#              #
#    Updated: 2023/07/16 16:06:48 by asaouab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCCLIENT = main_client.c used_fun.c
SRCSERVER = main_server.c used_fun.c
OBJECTS = $(SRCCLIENT:.c=.o)
OBJECTS1 = $(SRCSERVER:.c=.o)

all : $(CLIENT) $(SERVER)

bonus : $(CLIENT_BONUS) $(SERVER_BONUS)

client : $(OBJECTS) minitalk.h
	$(CC) $(CFLAGS) $(OBJECTS) -o $(CLIENT)

server : $(OBJECTS1) minitalk.h
	$(CC) $(CFLAGS) $(OBJECTS1) -o $(SERVER)

%.o : %.c minitalk.h
	$(CC) $(CFLAGS)  -c $<

clean :
	rm -rf $(OBJECTS) $(OBJECTS1) 

fclean : clean
	rm -rf $(CLIENT) $(SERVER)

re : fclean all
.PHONY: clean fclean