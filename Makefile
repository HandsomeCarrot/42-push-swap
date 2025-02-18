# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoka <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 13:14:45 by vpoka             #+#    #+#              #
#    Updated: 2025/02/18 20:21:48 by vpoka            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

ARNAME = ar rcs $(NAME)
RM = rm -f

LIBFT = ./libft/libft.a

SRCS =  push_swap.c \
		push.c \
		swap.c \
		rotate.c \
		reverse_rotate.c \
		list.c \
		sort.c \
		normalize.c \
		rotations.c \
		split.c \
		utils.c \
		stack.c \
		mod_atoi.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

$(LIBFT):
	$(MAKE) allbonus -C ./libft

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
