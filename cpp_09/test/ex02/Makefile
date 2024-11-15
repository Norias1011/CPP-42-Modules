NAME = PmergeMe

SRCS = main.cpp PmergeMe.cpp

CFLAGS = -Wall -Wextra -Werror -g -std=c++98

OBJS = $(SRCS:.cpp=.o)

CC = c++

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

$(OBJS): %.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)