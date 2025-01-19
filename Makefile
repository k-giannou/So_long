# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgiannou <kgiannou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 15:13:58 by kgiannou          #+#    #+#              #
#    Updated: 2025/01/18 17:56:12 by kgiannou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a

FTPRINTF = libft/ftprintf/libftprintf.a

MINIL = minilibx/libmlx_Linux.a

FLAGS = cc -Wall -Wextra -Werror -I/. -Iminilibx

SRC = so_long.c drawmap2.c drawmap.c free.c inits.c inits2.c checks.c errors.c moves.c path.c

OBJECT = $(SRC:%.c=%.o)

NAME = so_long

all: $(NAME)

$(NAME): $(MINIL) $(OBJECT) $(LIBFT) $(FTPRINTF)
	$(FLAGS) $(MINIL) $(OBJECT) $(LIBFT) $(FTPRINTF) -Lminilibx -lmlx_Linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "\033[32m<<< Ready, start with ./so_long heart.ber>>>\033[0m"

$(LIBFT):
	$(MAKE) -s -C ./libft

$(FTPRINTF):
	$(MAKE) -s -C ./libft/ftprintf

$(MINIL):
	$(MAKE) -s -C ./minilibx

clean:
	@make clean -s -C ./libft
	@make clean -s -C ./libft/ftprintf
	@make clean -s -C ./minilibx
	@rm -rf $(OBJECT)

fclean: clean
	@make fclean -s -C ./libft
	@make fclean -s -C ./libft/ftprintf
	@rm -rf $(NAME)
	@echo "\033[32m<<< It has been cleaned successfully >>>\033[0m"

re: fclean all
