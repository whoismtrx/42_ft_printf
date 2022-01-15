# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 15:37:42 by orekabe           #+#    #+#              #
#    Updated: 2022/01/15 04:47:41 by orekabe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

HEADER = ft_printf.h

SRC =	ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_puthex.c ft_putaddress.c ft_fill_width.c ft_fill_prec.c \
		ft_conversion1.c ft_conversion2.c ft_check_after_percentage.c ft_flags2.c ft_check_specifier.c ft_isdigit.c \
		ft_check_hash.c ft_check_plus.c ft_check_decimal.c ft_check_hexa.c ft_check_flags.c ft_get_flags1.c ft_print1.c ft_print2.c \
		ft_putnchar.c ft_putnstr.c ft_putnnbr.c ft_putunbr.c ft_putnhex.c ft_putnaddress.c ft_atoi.c ft_strlen.c ft_count_len.c ft_flags1.c

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
