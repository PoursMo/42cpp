CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98
NAME = btc
SRCS = main.cpp \
BitcoinExchange.cpp \

OBJS = ${SRCS:%.cpp=%.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.cpp
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all