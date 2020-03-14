# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 17:05:51 by jungeun           #+#    #+#              #
#    Updated: 2020/03/14 23:43:42 by jungeun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = srcs/ft_printf.c srcs/parsing.c srcs/parsing_utils.c\
	srcs/argument.c srcs/digit.c srcs/print.c \
	srcs/print_by_type.c srcs/print_utils.c
OBJ = $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -I includes/ -L. -lftprintf -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	ar rcsvT $(NAME) $(OBJ) $(LIBFT)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
