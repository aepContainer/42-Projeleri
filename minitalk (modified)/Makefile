CFLAGS = -Wall -Wextra -Werror
NAME = minitalk
SERVER = server
CLIENT = client
PRINTF_PATH = ./ft_printf
LIBFTPRINTF = $(PRINTF_PATH)/libftprintf.a
PRINTF_FLAGS = -L $(PRINTF_PATH) -l ftprintf

$(NAME): $(SERVER) $(CLIENT)

all: $(NAME)

$(SERVER): $(LIBFTPRINTF) $(SERVER).c
	$(CC) $(CFLAGS) $(SERVER).c -o $(SERVER) $(PRINTF_FLAGS)

$(CLIENT): $(LIBFTPRINTF) $(CLIENT).c
	$(CC) $(CFLAGS) $(CLIENT).c -o $(CLIENT) $(PRINTF_FLAGS)

$(LIBFTPRINTF):
	make -s --directory=$(PRINTF_PATH)

clean:
	make -s --directory=$(PRINTF_PATH) clean

fclean:	clean
	$(RM) $(SERVER) $(CLIENT) $(LIBFTPRINTF)

re: fclean all

.PHONY: all clean fclean re
