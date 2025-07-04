# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: weiyang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/04 13:24:39 by weiyang           #+#    #+#              #
#    Updated: 2025/07/04 13:28:47 by weiyang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap.a
FLAG = -Wall -Wextra -Werror
PATH_SRC = ./
SRC = operations.c parse.c sort.c
OBJ = $(SRC:.c=.o)
PATH_HEADER = ./
all: $(NAME)
$(NAME): $(OBJ)
	ar rc $(NAME) $^
$(PATH_SRC)%.o: $(PATH_SRC)%.c
	cc $(FLAG) -I$(PATH_HEADER) -c $< -o $@ 

clean: 
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all
