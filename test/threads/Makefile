CXX = g++-11
CC = $(CXX)

CPPFLAGS = -I$(INC_DIR)

# c++ language
CXXFLAGS = -std=c++20
CXXFLAGS+= -Wall -pedantic -pthread
CXXFLAGS+= -Werror
CXXFLAGS+= -g3


LDFLAGS =
LDLIBS =

INC_DIR = ../../inc
SRC_DIR = 

TARGET = utest assert_tests
OBJS = utest.o assert_tests.o

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

utest : utest.cpp $(INC_DIR)/thread_safe_queue.hpp

assert_tests : assert_tests.cpp $(INC_DIR)/thread_safe_queue.hpp

vala: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes


clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean vala