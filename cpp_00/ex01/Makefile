NAME = Phonebook

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRCS = Contact.cpp Phonebook.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -rf

.PHONY: all clean re fclean

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
    $(CC) $(FLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: clean all