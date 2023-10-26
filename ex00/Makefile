NAME = Fixed_one

SRCS = main.cpp 
OBJS = $(SRCS:.c=.o)
# HEADER = Fixed.hpp

C++ = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS) #$(HEADER)//
	$(C++) $(CFLAGS) $(OBJS) -o $(NAME)
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

