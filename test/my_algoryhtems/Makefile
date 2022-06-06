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
OBJS = utest.o person.o point.o my_algorythems.o

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

utest : utest.cpp $(INC_DIR)/person.hpp $(SRC_DIR)/person.cpp $(INC_DIR)/point.hpp $(SRC_DIR)/point.cpp $(INC_DIR)/my_algorythems.hpp $(SRC_DIR)/my_algorythems.cpp

vala: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET) 


clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean vala