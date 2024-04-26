NAME    = ircserv
CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++17 -fsanitize=address -g3
SRC_D   = srcs/
INC_D   = includes/
OBJ_D   = obj/

SRC     = 	main.cpp \
			Server.cpp \
			Client.cpp \
			Channel.cpp \
			Commands.cpp \
			./commands/ACommand.cpp \
			./commands/NICK.cpp \
			./commands/PASS.cpp \
			./commands/PING.cpp \
			./commands/PONG.cpp \
			./commands/PRIVMSG.cpp \
			./commands/USER.cpp \
			./commands/RPL_WELCOME.cpp \
			./commands/RPL_YOURHOST.cpp \
			./commands/RPL_CREATED.cpp \
			./commands/RPL_MYINFO.cpp \
			./commands/RPL_ISUPPORT.cpp \
			./commands/RPL_UMODEIS.cpp \
			./commands/RPL_LUSERCLIENT.cpp \
			./commands/RPL_LUSERME.cpp \
			./commands/ERR_UNKNOWNERROR.cpp \
			./commands/ERR_NOSUCHNICK.cpp \
			./commands/ERR_NOSUCHCHANNEL.cpp \
			./commands/ERR_NORECIPIENT.cpp \
			./commands/ERR_NOTEXTTOSEND.cpp \
			./commands/ERR_UNKNOWNCOMMAND.cpp \
			./commands/ERR_NOMOTD.cpp \
			./commands/ERR_NONICKNAMEGIVEN.cpp \
			./commands/ERR_ERRONEUSNICKNAME.cpp \
			./commands/ERR_NICKNAMEINUSE.cpp \
			./commands/ERR_NOTREGISTERED.cpp \
			./commands/ERR_NEEDMOREPARAMS.cpp \
			./commands/ERR_ALREADYREGISTERED.cpp \
			./commands/ERR_PASSWDMISMATCH.cpp \

OBJ_D   = obj/
OBJ     = $(SRC:.cpp=.o)
OBJS    = $(addprefix $(OBJ_D), $(OBJ))

INC     = -I$(INC_D) -I$(INC_D)commands/

HEADERS = $(addprefix $(INC_D), $(filter-out main.hpp,$(SRC:.cpp=.hpp)))

all: $(NAME)

$(OBJ_D)%.o: $(SRC_D)%.cpp $(HEADERS)
	mkdir -p $(OBJ_D)
	mkdir -p $(OBJ_D)commands
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_D)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
