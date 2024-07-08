# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 16:32:51 by apalaz            #+#    #+#              #
#    Updated: 2024/05/23 16:32:51 by apalaz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT_PATH) -I $(PUSH_SWAP_UTILS_PATH) -I $(PUSH_SWAP_CMDS_PATH)
AR = ar rcs
RM = rm -rf
LIBFT_PATH = ../libft/
LIBFT = $(LIBFT_PATH)libft.a
SRCS = checker_bonus.c utils_bonus.c check.c utils.c free_and_error.c \
moves/push.c moves/rev_rotate.c moves/rotate.c moves/swap.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cc $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
