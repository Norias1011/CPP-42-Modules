NAME = megaphone

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

RM = rm -rf

.PHONY: all clean re

all: $(NAME)

$(NAME):
		$(CC) $(FLAGS) megaphone.cpp -o $(NAME)

clean:
		$(RM) $(NAME)

fclean:
		$(RM) $(NAME)

re: clean all