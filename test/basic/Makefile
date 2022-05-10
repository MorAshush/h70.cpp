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

INC_DIR =../../inc/
SRC_DIR =../../src/

TARGET = utests
OBJS = utests.o first_class.o

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

utests : utests.cpp $(SRC_DIR)first_class.cpp $(INC_DIR)first_class.hpp

clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean