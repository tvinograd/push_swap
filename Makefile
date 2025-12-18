# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/11 12:49:29 by tvinogra          #+#    #+#              #
#    Updated: 2025/12/18 13:11:48 by tvinogra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
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
radix.c \
sort.c \
main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
