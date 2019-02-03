# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghaas <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 10:45:22 by ghaas             #+#    #+#              #
#    Updated: 2018/03/13 11:00:28 by ghaas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = src
SRC_NAME = main.c\
		functions.c\
		display.c\
		read_file.c\
		user_interface.c\

CPPFLAGS = -Iinclude

NAME = FDF

LOGIN = ghaas

CC = gcc

CFLAGS = -Werror -Wall -Wextra

LIBFT = libft/libft.a

MLX = minilibx_macos/libmlx.a

FW = -framework OpenGL -framework AppKit

OBJ = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

all: $(NAME)

$(NAME):
		@make -C libft/
		@make -C minilibx_macos/
		@$(CC) $(CFLAGS) -c $(SRC) $(CPPFLAGS)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX) $(FW)
		@echo "\033[38;5;32m  [$(NAME)]	Compiled."
		@echo "\033[34m"
		@echo "\033[38;5;24m  MMMºººAMV      MMºººMM        MMºººMM    MMºººMm"
		@echo " MM             MM     MM'     MM     MM   MM    Mm"
		@echo "\033[38;5;25m MM            MM       MM'   MM       MM  MM     mm"
		@echo " MM            MM       MM'   MM       MM  MM      M"
		@echo "\033[38;5;26m MM   AMVMMAMV MM       MM'   MM       MM  MM     mm"
		@echo " MM      MM     MM     MM'     MM     MM   MM    Mm"
		@echo "\033[38;5;27m  AMVmmmmMM      MMwwwMM        MMwwwMM    MMwwwMM "
		@echo ""
		@echo "\033[38;5;32m [2018]                    [${LOGIN}]"
		@echo ""

clean:
		@make clean -C libft/
		@make clean -C minilibx_macos/
		@rm -rf $(OBJ)

fclean: clean
		@make fclean -C libft/
		@rm -rf $(NAME)

re: fclean all
