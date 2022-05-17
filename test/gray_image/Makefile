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
OBJS = utest.o $(SRC_DIR)/gray_image.o

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

utest : utest.cpp $(SRC_DIR)/gray_image.cpp $(INC_DIR)/gray_image.hpp

vala: $(TARGET)
	valgrind ./$(TARGET) 


clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean vala