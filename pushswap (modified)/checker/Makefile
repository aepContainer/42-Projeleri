NAME = checker
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT_PATH)
AR = ar rcs
RM = rm -rf
LIBFT_PATH = ../libft/
LIBFT = $(LIBFT_PATH)libft.a
SRCS = checker_bonus.c utils_bonus.c check.c utils.c free_and_error.c \
find_last_node.c moves/push.c moves/rev_rotate.c moves/rotate.c moves/swap.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	cc $(OBJS) $(LIBFT) -o $(NAME)

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
