CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98
NAME = ex03
SRCS = main.cpp \
HumanA.cpp \
HumanB.cpp \
Weapon.cpp \

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