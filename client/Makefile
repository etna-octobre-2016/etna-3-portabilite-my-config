# source directory 
SRCDIR= src

# the compiler: g++ for C++ on UNIX and cl for Windows
#CC = cl
CC = g++


# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall -std=c++11
#CFLAGS = /clr


SRC = $(SRCDIR)/main.cpp \
		$(SRCDIR)/socket.cpp \
		

RM = rm -rf
# the build target executable:
TARGET = cpp

OBJS = $(SRC:%.cpp=%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(TARGET)

re:		fclean all
