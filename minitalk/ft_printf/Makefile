# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 15:07:30 by hel-hich          #+#    #+#              #
#    Updated: 2022/02/17 00:13:44 by hel-hich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_printf_utiles.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ) 

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re