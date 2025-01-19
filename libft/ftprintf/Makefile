# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 18:18:40 by kgiannou          #+#    #+#              #
#    Updated: 2024/11/17 18:25:27 by kgiannou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra

CC = cc

NAME = libftprintf.a

SRCS = ft_printf.c prints.c prints2.c utils.c

OBJECTS = $(SRCS:%.c=%.o)

$(NAME):
	$(CC) $(FLAGS) -c $(SRCS) -I./
	ar rcs $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
