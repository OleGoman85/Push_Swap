# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 12:14:59 by utente            #+#    #+#              #
#    Updated: 2024/01/13 09:03:58 by ogoman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

PUSH_SWAP_DIR = push_swap_project
CHECKER_DIR = checker_bonus

PUSH_SWAP_SRCS = main.c error_free.c push_command.c \
                push_swap_command.c push_swap_init.c \
                tiny_sort.c swap_command.c stack_utils.c \
                stack_init.c split.c rotate_command.c \
                reverse_rotate_command.c

# PUSH_SWAP.o
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:%.c=$(PUSH_SWAP_DIR)/%.o)

INCLUDE_CHECKER_SRCS = push_command.c error_free.c \
                push_swap_command.c push_swap_init.c \
                tiny_sort.c swap_command.c stack_utils.c \
                stack_init.c split.c rotate_command.c \
                reverse_rotate_command.c

# INCLUDES_CHECKER_OBJS.o
INCLUDE_CHECKER_OBJS = $(INCLUDE_CHECKER_SRCS:%.c=$(PUSH_SWAP_DIR)/%.o)

CHECKER_SRCS = checker.c get_next_line_utils.c \
		get_next_line.c

# # CHECHER.o
CHECKER_OBJS = $(CHECKER_SRCS:%.c=$(CHECKER_DIR)/%.o)

all: $(NAME)
	
# push_swap
$(NAME): $(PUSH_SWAP_OBJS) 
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJS) -o $(NAME)
	
# checker
$(BONUS): $(CHECKER_OBJS) $(INCLUDE_CHECKER_OBJS)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) $(INCLUDE_CHECKER_OBJS) -o $(BONUS)

bonus: $(BONUS)
	
clean:
	$(RM) $(PUSH_SWAP_DIR)/*.o $(CHECKER_DIR)/*.o

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re