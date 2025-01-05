# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/04 16:55:21 by abdsebba          #+#    #+#              #
#    Updated: 2025/01/05 23:20:49 by abdsebba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
BONUS=checker

CC=cc
CFLAGS=-Wall -Wextra -Werror

SRC=check_argument.c first_algorithm.c ft_split.c push_swap.c push_command.c reverse_rotate.c secon_utls.c swap_ar.c \
	create_list.c free_succ.c handler_n.c push_ar.c push_utls.c rotate_ar.c second_algorithm.c

SRC_BONUS=checker.c get_next_line_utils.c get_next_line.c check_argument.c ft_split.c reverse_rotate.c swap_ar.c \
	create_list.c free_succ.c push_ar.c push_utls.c rotate_ar.c checker_utils.c

OBJ_BONUS=$(SRC_BONUS:.c=.o)
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $@

%.o:%.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re