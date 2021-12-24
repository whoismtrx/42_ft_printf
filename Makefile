# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 15:37:42 by orekabe           #+#    #+#              #
#    Updated: 2021/12/22 02:33:39 by orekabe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

HEADER = ft_printf.h

SRC =	ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_puthex.c ft_putaddress.c \
		ft_conversion.c ft_check_after_percentage.c ft_check_flags2.c ft_check_specifier.c \
		ft_check_hash.c ft_check_plus.c ft_check_decimal.c ft_check_hexa.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

bonus: re
	