NAME    = ircserv
CC      = c++
CFLAGS  = -Wall -Wextra -Werror -fsanitize=address -g3
SRC_D   = srcs/
INC_D   = includes/
OBJ_D   = obj/

SRC     = main.cpp Server.cpp Client.cpp Channel.cpp
SRCS    = $(addprefix $(SRC_D), $(SRC))

OBJ_D   = obj/
OBJ     = $(SRC:.cpp=.o)
OBJS    = $(addprefix $(OBJ_D), $(OBJ))

INC     = -I$(INC_D)

all: $(NAME)

$(OBJ_D)%.o: $(SRC_D)%.cpp
	mkdir -p $(OBJ_D)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_D)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
