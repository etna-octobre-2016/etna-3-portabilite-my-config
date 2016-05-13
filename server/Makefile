# source directory 
SRCDIR= src

# the compiler: g++ for C++ on UNIX and cl for Windows
CCWIN = cl
CCMAC = g++


# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGSMAC  = -g -Wall
CFLAGSWIN = /clr


SRC = $(SRCDIR)/main.cpp \
		$(SRCDIR)/memory.cpp \
		$(SRCDIR)/hdd.cpp \
		$(SRCDIR)/socket.cpp \
		$(SRCDIR)/client.cpp \

SRCMAC = $(SRCDIR)/macos.cpp \
		$(SRCDIR)/cpumac.cpp

SRCWIN = $(SRCDIR)/windowsos.cpp \
			$(SRCDIR)/cpuwin.cpp 

SRCLINUX = $(SRCDIR)/linuxos.cpp \
			$(SRCDIR)/cpulinux.cpp 

RM = rm -rf
# the build target executable:
TARGET = server


OBJS = $(SRC:%.cpp=%.o)

OBJSMAC = $(SRCMAC:%.cpp=%.o)

OBJSWIN = $(SRCWIN:%.cpp=%.o)

OBJSLINUX = $(SRCLINUX:%.cpp=%.o)

#all: $(TARGET)

mac: mactarget
win: wintarget
linux: linuxtarget

mactarget: $(OBJS) $(OBJSMAC)
	$(CCMAC) $(CFLAGSMAC) $(OBJS) $(OBJSMAC) -o $(TARGET)

wintarget: $(OBJS) $(OBJSWIN)
	$(CCWIN) $(CFLAGSWIN) $(OBJS) $(OBJSWIN) -o $(TARGET)

linuxtarget: $(OBJS) $(OBJSLINUX)
	$(CCMAC) $(CFLAGSMAC) $(OBJS) $(OBJSLINUX) -o $(TARGET)

clean:
		$(RM) $(SRCDIR)/*.o $(TARGET)

fclean:		clean
		$(RM) $(TARGET)

re:		fclean all
