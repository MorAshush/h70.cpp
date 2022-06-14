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

INC_DIR = ../../inc/stack_machine
SRC_DIR = ../../src/stack_machine

TARGET = utest
OBJS = utest.o $(SRC_DIR)/virtual_machine.o $(SRC_DIR)/stack.o $(SRC_DIR)/add.o

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

utest : utest.cpp $(SRC_DIR)/virtual_machine.cpp $(INC_DIR)/virtual_machine.hpp \
					$(SRC_DIR)/stack.cpp $(INC_DIR)/stack.hpp \
					$(SRC_DIR)/instruction_base.cpp $(INC_DIR)/instruction_base.hpp \
					$(SRC_DIR)/add.cpp $(INC_DIR)/add.hpp

vala: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)


clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean vala