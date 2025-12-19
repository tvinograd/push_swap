# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/11 12:49:29 by tvinogra          #+#    #+#              #
#    Updated: 2025/12/19 13:40:23 by tvinogra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = \
ft_atoi_ps.c \
stack.c \
parse.c \
index.c \
op_swap.c \
op_push.c \
op_rot.c \
op_rev_rot.c \
sort_radix.c \
sort_small.c \
sort.c \
main.c

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
