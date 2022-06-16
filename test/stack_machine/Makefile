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
OBJS = utest.o $(SRC_DIR)/virtual_machine.o \
				$(SRC_DIR)/stack.o \
				$(SRC_DIR)/instruction_base.o \
				$(SRC_DIR)/instruction_arg.o \
				$(SRC_DIR)/nop.o \
				$(SRC_DIR)/add.o \
				$(SRC_DIR)/sub.o \
				$(SRC_DIR)/and.o \
				$(SRC_DIR)/hlt.o \
				$(SRC_DIR)/load.o \
				$(SRC_DIR)/push.o \
				$(SRC_DIR)/memory.o \
				$(SRC_DIR)/grammar.o \
				$(SRC_DIR)/parser.o \
				$(SRC_DIR)/factory.o \
				$(SRC_DIR)/program_loader.o \
				$(SRC_DIR)/virtual_machine.o \
				$(SRC_DIR)/instruction_pointer.o \
				$(SRC_DIR)/controller.o \

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

utest : utest.cpp $(SRC_DIR)/virtual_machine.cpp $(INC_DIR)/virtual_machine.hpp \
					$(SRC_DIR)/stack.cpp $(INC_DIR)/stack.hpp \
					$(SRC_DIR)/instruction_base.cpp $(INC_DIR)/instruction_base.hpp \
					$(SRC_DIR)/instruction_arg.cpp $(INC_DIR)/instruction_arg.hpp \
					$(SRC_DIR)/nop.cpp $(INC_DIR)/nop.hpp \
					$(SRC_DIR)/add.cpp $(INC_DIR)/add.hpp \
					$(SRC_DIR)/sub.cpp $(INC_DIR)/sub.hpp \
					$(SRC_DIR)/and.cpp $(INC_DIR)/and.hpp \
					$(SRC_DIR)/hlt.cpp $(INC_DIR)/hlt.hpp \
					$(SRC_DIR)/load.cpp $(INC_DIR)/load.hpp \
					$(SRC_DIR)/push.cpp $(INC_DIR)/push.hpp \
					$(SRC_DIR)/memory.cpp $(INC_DIR)/memory.hpp \
					$(SRC_DIR)/grammar.cpp $(INC_DIR)/grammar.hpp \
					$(SRC_DIR)/parser.cpp $(INC_DIR)/parser.hpp \
					$(SRC_DIR)/factory.cpp $(INC_DIR)/factory.hpp \
					$(SRC_DIR)/program_loader.cpp $(INC_DIR)/program_loader.hpp \
					$(SRC_DIR)/virtual_machine.cpp $(INC_DIR)/virtual_machine.hpp \
					$(SRC_DIR)/instruction_pointer.cpp $(INC_DIR)/instruction_pointer.hpp \
					$(SRC_DIR)/controller.cpp $(INC_DIR)/controller.hpp \

vala: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)


clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean vala