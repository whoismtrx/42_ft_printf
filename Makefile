# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 15:37:42 by orekabe           #+#    #+#              #
#    Updated: 2022/01/15 20:23:42 by orekabe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

HEADER = -I./include

SRCD = ./src

OBJD = ./objs

SRC =	$(SRCD)/ft_printf.c $(SRCD)/ft_putchar.c $(SRCD)/ft_putstr.c $(SRCD)/ft_putnbr.c $(SRCD)/ft_puthex.c $(SRCD)/ft_putaddress.c $(SRCD)/ft_fill_width.c $(SRCD)/ft_fill_prec.c \
		$(SRCD)/ft_conversion1.c $(SRCD)/ft_conversion2.c $(SRCD)/ft_flags2.c $(SRCD)/ft_check_specifier.c $(SRCD)/ft_isdigit.c $(SRCD)/ft_flags2_w.c $(SRCD)/ft_print1.c $(SRCD)/ft_print2.c \
		$(SRCD)/ft_check_hash.c $(SRCD)/ft_check_plus.c $(SRCD)/ft_check_decimal.c $(SRCD)/ft_check_hexa.c $(SRCD)/ft_check_flags.c $(SRCD)/ft_get_flags1.c $(SRCD)/ft_strlen.c $(SRCD)/ft_count_len.c \
		$(SRCD)/ft_putnchar.c $(SRCD)/ft_putnstr.c $(SRCD)/ft_putnnbr.c $(SRCD)/ft_putunbr.c $(SRCD)/ft_putnhex.c $(SRCD)/ft_putnaddress.c $(SRCD)/ft_atoi.c  $(SRCD)/ft_flags1.c $(SRCD)/ft_check_after_percentage.c

OBJ = $(addprefix $(OBJD)/, $(notdir $(SRC:.c=.o)))

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $^
	@echo "███████╗████████╗     ██████╗ ██████╗ ██╗███╗   ██╗████████╗███████╗"
	@echo "██╔════╝╚══██╔══╝     ██╔══██╗██╔══██╗██║████╗  ██║╚══██╔══╝██╔════╝"
	@echo "█████╗     ██║        ██████╔╝██████╔╝██║██╔██╗ ██║   ██║   █████╗  "
	@echo "██╔══╝     ██║        ██╔═══╝ ██╔══██╗██║██║╚██╗██║   ██║   ██╔══╝"
	@echo "██║        ██║███████╗██║     ██║  ██║██║██║ ╚████║   ██║   ██║   "
	@echo "╚═╝        ╚═╝╚══════╝╚═╝     ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝  "
	@echo "                   BY: MTRX         "

$(OBJD)/%.o: $(SRCD)/%.c
	@mkdir -p $(OBJD)
	@printf "Compiling $<\r"
	@$(CC) -c $(CFLAGS) $(HEADER) $< -o $@

clean:
	rm -rf $(OBJD)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: re
