CXX = g++
CC = $(CXX)

CPPFLAGS = -I$(INC_DIR)
# c language
CFLAGS = -g3

# c++ language
CXXFLAGS = -std=c++17
CXXFLAGS+= -Wall -pedantic
CXXFLAGS+= -Werror
CXXFLAGS+= -g3


LDFLAGS =
LDLIBS =

INC_DIR = ../../inc
SRC_DIR = ../../src

TARGET = unique_ptr
OBJS = unique_ptr.o $(SRC_DIR)/rational.o

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

unique_ptr : unique_ptr.cpp $(SRC_DIR)/rational.cpp $(INC_DIR)/rational.hpp

clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean