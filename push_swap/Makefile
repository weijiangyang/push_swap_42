# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: weiyang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/04 13:24:39 by weiyang           #+#    #+#              #
#    Updated: 2025/07/12 17:39:59 by weiyang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAG = -Wall -Wextra -Werror
SRC_DIR = src
INCLUDE_DIR = includes

SRC = operations.c parse.c sort.c main.c 
OBJ = $(SRC:.c=.o)

SRC_PATHS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJ_PATHS = $(addprefix $(SRC_DIR)/, $(OBJ))

all: $(NAME)

$(NAME): $(OBJ_PATHS)
	cc $(FLAG) -I$(INCLUDE_DIR) -o $(NAME) $(OBJ_PATHS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	cc $(FLAG) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(OBJ_PATHS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re

