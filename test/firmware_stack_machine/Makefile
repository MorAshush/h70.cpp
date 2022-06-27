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

INC_DIR = ../../inc/firmware_stack_machine
SRC_DIR = ../../src/firmware_stack_machine

TARGET = utest
OBJS = utest.o $(SRC_DIR)/virtual_machine.o \
				$(SRC_DIR)/functions.o \
				$(SRC_DIR)/stack.o \
				$(SRC_DIR)/bus.o \
				$(SRC_DIR)/mapper.o \
				$(SRC_DIR)/parser.o \
				$(SRC_DIR)/controller.o \
				$(SRC_DIR)/memory.o \
				$(SRC_DIR)/error.o \
				$(SRC_DIR)/stack_overflow.o \
				$(SRC_DIR)/stack_underflow.o \
				$(SRC_DIR)/segmentation_fault.o \
				$(SRC_DIR)/invalid_instruction.o \
				$(SRC_DIR)/missing_argument.o \

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

utest : utest.cpp $(SRC_DIR)/virtual_machine.cpp $(INC_DIR)/virtual_machine.hpp \
					$(SRC_DIR)/functions.cpp $(INC_DIR)/functions.hpp \
					$(SRC_DIR)/stack.cpp $(INC_DIR)/stack.hpp \
					$(SRC_DIR)/bus.cpp $(INC_DIR)/bus.hpp \
					$(SRC_DIR)/mapper.cpp $(INC_DIR)/mapper.hpp \
					$(SRC_DIR)/parser.cpp $(INC_DIR)/parser.hpp \
					$(SRC_DIR)/controller.cpp $(INC_DIR)/controller.hpp \
					$(SRC_DIR)/memory.cpp $(INC_DIR)/memory.hpp \
					$(SRC_DIR)/error.cpp $(INC_DIR)/error.hpp \
					$(SRC_DIR)/stack_overflow.cpp $(INC_DIR)/stack_overflow.hpp \
					$(SRC_DIR)/stack_underflow.cpp $(INC_DIR)/stack_underflow.hpp \
					$(SRC_DIR)/segmentation_fault.cpp $(INC_DIR)/segmentation_fault.hpp \
					$(SRC_DIR)/invalid_instruction.cpp $(INC_DIR)/invalid_instruction.hpp \
					$(SRC_DIR)/missing_argument.cpp $(INC_DIR)/missing_argument.hpp \
					

vala: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)


clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean vala