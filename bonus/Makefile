# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jesumore <jesumore@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/25 16:31:28 by jesumore          #+#    #+#              #
#    Updated: 2024/09/05 18:57:53 by jesumore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex_bonus

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror -Iinclude

PIPEX = ../libpipex.a

LIBFT = ../Libft/libft.a

SRCS = main_bonus.c pipex_utils_bonus.c errors_bonus.c command_exec_bonus.c \
		get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:%.c=%.o)

RM = rm -f

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(LIBFT):
	@cd ../Libft && make -s

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re