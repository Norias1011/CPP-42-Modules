NAME = bank

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRCS = Account.cpp tests.cpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -rf

.PHONY: all clean re fclean

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: clean all