RM := rm -rf
CC := c++
CXXFLAGS := -std=c++17

NAME := database

INCLUDE := /opt/homebrew/Cellar/libpqxx/7.8.1/include
LIB := /opt/homebrew/Cellar/libpqxx/7.8.1/lib
SRCS := main.cpp usingQuery.cpp
OBJS := $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $^ -L$(LIB) -I$(INCLUDE) -lpqxx 

%.o : %.cpp
	$(CC) $(CXXFLAGS) -o $@ $< -c -I$(INCLUDE) -IusingQuery.hpp

clean :
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
