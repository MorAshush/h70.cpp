CPPFLAGS = -I$(INC_DIR)
# c language
CFLAGS = -g3

# c++ language
CXXFLAGS = -std=c++17
CXXFLAGS+= -Wall -pedantic
CXXFLAGS+= -Werror
CXXFLAGS+= -g3 -pthread


LDFLAGS =
LDLIBS =

INC_DIR = ../../inc
SRC_DIR = 

TARGET = utest
OBJS = utest.o

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

utest : utest.cpp

vala: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes


clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean vala