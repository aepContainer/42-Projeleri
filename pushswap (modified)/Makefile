NAME = push_swap
AR_NAME = push_swap.a
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT_PATH) 
AR = ar rcs
RM = rm -rf
LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a
CHECKER_PATH = checker/
CHECKER_NAME = checker
SRCS = src/push_swap.c src/sort_stack.c src/init_a_to_b.c src/init_b_to_a.c \
src/utils/check.c src/utils/find_node.c src/utils/free_and_error.c \
src/utils/utils.c src/utils/stack_utils.c src/moves/push.c src/moves/swap.c \
src/moves/rotate.c src/moves/rev_rotate.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
	cc $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -s -C $(LIBFT_PATH)

$(AR_NAME): $(LIBFT) $(OBJS) 
	$(AR) $(AR_NAME) $(OBJS) $(LIBFT_PATH)*.o

bonus:	$(AR_NAME)
	make -s -C $(CHECKER_PATH)

clean:
	$(RM) $(OBJS)
	make -s -C $(LIBFT_PATH) clean
	make -s -C $(CHECKER_PATH) clean

fclean: clean
	make -s -C $(LIBFT_PATH) fclean
	make -s -C $(CHECKER_PATH) fclean
	$(RM) $(NAME)
	$(RM) $(AR_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
