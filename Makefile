# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/20 19:38:52 by jesumore          #+#    #+#              #
#    Updated: 2024/08/26 23:57:33 by jesumore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iinclude

LIBRARY = libpipex.a

AR = ar

ARFLAGS = -rcs

LIBFT = Libft/libft.a

SRCS = main.c pipex_utils.c command_exec.c

OBJS = $(SRCS:%.c=%.o)

RM = rm -f

all: $(NAME) $(LIBRARY)

$(NAME): $(OBJS) $(LIBRARY) $(LIBFT)
	@$(CC) $(OBJS) $(LIBRARY) $(LIBFT) -o $@

$(LIBRARY): $(OBJS)
	@$(AR) $(ARFLAGS) $(LIBRARY) $(OBJS)

$(LIBFT):
	@make -s -C ./Libft all

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus:
	@cd bonus/ && make

clean:
	@$(RM) $(OBJS) $(LIBRARY)
	@cd Libft/ && make clean 

fclean: clean
	@$(RM) $(NAME)
	@cd Libft/ && make fclean
	@cd bonus/ && make fclean 

re: fclean all

.PHONY: all clean fclean re libft bonus