CXX = g++-11
CC = $(CXX)

CPPFLAGS = -I$(INC_DIR) -I$(INC_DIR_2)

# c++ language
CXXFLAGS = -std=c++20
CXXFLAGS+= -Wall -pedantic -pthread
CXXFLAGS+= -Werror
CXXFLAGS+= -g3


LDFLAGS =
LDLIBS =

INC_DIR = ../../inc/threads
INC_DIR_2 = ../../inc
SRC_DIR = ../../src/threads

TARGET = utest assert_tests
OBJS = utest.o assert_tests.o

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

utest : utest.cpp $(INC_DIR)/thread_safe_queue.hpp $(SRC_DIR)/semaphore.o $(INC_DIR)/semaphore_error.hpp $(SRC_DIR)/semaphore_error.o

assert_tests : assert_tests.cpp $(INC_DIR)/thread_safe_queue.hpp $(SRC_DIR)/semaphore.o $(INC_DIR)/semaphore_error.hpp $(SRC_DIR)/semaphore_error.o

vala: $(TARGET)
	valgrind --leak-check=full --track-origins=yes --log-file=logValgrind01.txt ./$(TARGET)
	valgrind --tool=helgrind --log-file=loghelgrind01.txt ./$(TARGET)
	valgrind --tool=drd --log-file=logdrd01.txt ./$(TARGET)


clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean vala