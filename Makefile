NAME = irc_server
CC = c++
CFLAGS = -Wall -Wextra -Werror

SRCS = main.cpp

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

fclean:
	rm -rf $(NAME)

.PHONY all fclean
