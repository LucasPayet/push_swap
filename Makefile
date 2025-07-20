# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/19 18:50:32 by lupayet           #+#    #+#              #
#    Updated: 2025/07/20 01:12:07 by lupayet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = push_swap

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -g
RM = rm -f
LIBFT_P = ./libft/
LIBFT = $(LIBFT_P)libft.a

SRC	= main.c parser.c utils.c stack_utils.c

OBJ	= $(SRC:.c=.o)

%.o: %.c push_swap.h
	$(CC) -Wall -Wextra -Werror -c $< -o $@

all: $(NAME)

$(LIBFT):
	@echo "\nCOMPILING LIBFT..."
	@make -C $(LIBFT_P) 1>/dev/null
	@echo "> LIBFT CREATED"

$(NAME): $(LIBFT) $(OBJ)
	@echo "\nCOMPILING $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_P)libft.a -o $(NAME)
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
