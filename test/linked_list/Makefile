CXX = g++
CC = $(CXX)

CPPFLAGS = -I$(INC_DIR)
# c language
CFLAGS = -g3

# c++ language
CXXFLAGS = -std=c++03
CXXFLAGS+= -Wall -pedantic
CXXFLAGS+= -Werror
CXXFLAGS+= -g3


LDFLAGS =
LDLIBS =

INC_DIR = ../../inc
SRC_DIR = ../../src

TARGET = utest
OBJS = utest.o 

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

utest : utest.cpp $(INC_DIR)/slist.hpp

vala: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET) 


clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean vala