RM := rm -rf
CC := c++
CXXFLAGS := -std=c++17

NAME := database

INCLUDES := includes
INC_PQXX := /opt/homebrew/Cellar/libpqxx/7.8.1/include
LIB := /opt/homebrew/Cellar/libpqxx/7.8.1/lib

SRCS := main.cpp \
		$(addprefix srcs/, usingQuery.cpp printData.cpp)
OBJS := $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $^ -L$(LIB) -I$(INC_PQXX) -lpqxx

%.o : %.cpp
	$(CC) $(CXXFLAGS) -o $@ $< -c -I$(INC_PQXX) -I$(INCLUDES)

clean :
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
