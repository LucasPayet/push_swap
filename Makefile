# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/19 18:50:32 by lupayet           #+#    #+#              #
#    Updated: 2025/07/21 14:34:52 by lupayet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#.SILENT:

NAME = push_swap

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -g
RM = rm -f
SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc
LIBFT_P = ./libft/
LIBFT = $(LIBFT_P)libft.a

SRC	= main.c parser.c utils.c stack_utils.c swap.c

OBJ	= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -Wall -Wextra -Werror -I$(LIBFT_P) -I$(INC_DIR) -g -c $< -o $@

all: $(NAME)

$(LIBFT):
	@echo "\nCOMPILING LIBFT..."
	@make -C $(LIBFT_P) 1>/dev/null
	@echo "> LIBFT CREATED"

$(NAME): $(LIBFT) $(OBJ)
	@echo "\nCOMPILING $(NAME)\n $(OBJ)..."
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_P)libft.a -g -o $(NAME)
	@echo "> $(NAME) READY"

clean:
	@make clean -C $(LIBFT_P) 1>/dev/null
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT_P) 1>/dev/null
	@rm -f $(NAME)

re:fclean all

dev: re
	@make clean 1>/dev/null

.PHONY: all clean fclean re dev
