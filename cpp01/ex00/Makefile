CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98
NAME = ex00
SRCS = main.cpp \
newZombie.cpp \
Zombie.cpp \
randomChump.cpp \

OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $@

%.o: %.cpp
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all