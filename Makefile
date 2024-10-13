CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus
NAME = $(NAME_SERVER) $(NAME_CLIENT)

all: $(NAME)


$(NAME_SERVER): $(LIBFT) server.c
	$(CC) $(CFLAGS) $^ -o $@
	$(CC) $(CFLAGS) $^ -o $@

$(NAME_CLIENT): $(LIBFT) client.c
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(LIBFT) bonus/server.c
	$(CC) $(CFLAGS) $^ -o $@

$(NAME_CLIENT_BONUS): $(LIBFT) bonus/client.c
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	make all -C libft
clean:
	make clean -C libft

fclean:
	make fclean -C libft
	rm -f server
	rm -f client
	rm -f server_bonus
	rm -f client_bonus

re : fclean all

.PHONY: bonus
