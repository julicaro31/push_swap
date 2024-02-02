# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 22:09:00 by juliacaro         #+#    #+#              #
#    Updated: 2023/11/30 19:12:19 by jcaro            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = push_swap.c \
					checkers.c \
					push_swap_utils.c \
					operations/swap.c \
					operations/push.c \
					operations/rotate.c \
					operations/reverse.c \
					algorithms/algorithms_utils.c \
					algorithms/sort.c \
					algorithms/three_numbers.c \
					algorithms/big_sort.c \
					algorithms/setters.c \
					algorithms/to_the_top.c
OBJS = ${SRCS:.c=.o}
INCLUDE = include
CC = cc
FLAGS = -Wall -Wextra -Werror
LIBFT = libft.a
MAKE = make

%.o:%.c
	$(CC) $(FLAGS) -I$(INCLUDE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft -f Makefile
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) -L./libft -lft

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean $(NAME)

.PHONY: all clean fclean re