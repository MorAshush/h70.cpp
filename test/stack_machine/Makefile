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

INC_DIR = ../../inc/stack_machine
SRC_DIR = ../../src/stack_machine

TARGET = utest
OBJS = utest.o $(SRC_DIR)/virtual_machine.o \
				$(SRC_DIR)/stack_template.o \
				$(SRC_DIR)/instruction_base.o \
				$(SRC_DIR)/instruction_arg.o \
				$(SRC_DIR)/bus.o \
				$(SRC_DIR)/nop.o \
				$(SRC_DIR)/add.o \
				$(SRC_DIR)/sub.o \
				$(SRC_DIR)/and.o \
				$(SRC_DIR)/hlt.o \
				$(SRC_DIR)/load.o \
				$(SRC_DIR)/push.o \
				$(SRC_DIR)/or.o \
				$(SRC_DIR)/xor.o \
				$(SRC_DIR)/not.o \
				$(SRC_DIR)/stor.o \
				$(SRC_DIR)/jmp.o \
				$(SRC_DIR)/jz.o \
				$(SRC_DIR)/dup.o \
				$(SRC_DIR)/swap.o \
				$(SRC_DIR)/rol3.o \
				$(SRC_DIR)/jnz.o \
				$(SRC_DIR)/drop.o \
				$(SRC_DIR)/compl.o \
				$(SRC_DIR)/in.o \
				$(SRC_DIR)/out.o \
				$(SRC_DIR)/innum.o \
				$(SRC_DIR)/outnum.o \
				$(SRC_DIR)/memory.o \
				$(SRC_DIR)/grammar.o \
				$(SRC_DIR)/parser.o \
				$(SRC_DIR)/factory.o \
				$(SRC_DIR)/program_loader.o \
				$(SRC_DIR)/virtual_machine.o \
				$(SRC_DIR)/controller.o \
				$(SRC_DIR)/error.o \
				$(SRC_DIR)/stack_overflow.o \
				$(SRC_DIR)/stack_underflow.o \
				$(SRC_DIR)/segmentation_fault.o \
				$(SRC_DIR)/invalid_instruction.o \
				$(SRC_DIR)/missing_argument.o \
				$(SRC_DIR)/token_base.o \
				$(SRC_DIR)/tnum.o \
				$(SRC_DIR)/tstr.o \
				$(SRC_DIR)/tcmd.o \
				$(SRC_DIR)/tdata.o \

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

utest : utest.cpp $(SRC_DIR)/virtual_machine.cpp $(INC_DIR)/virtual_machine.hpp \
					$(INC_DIR)/stack_template.hpp \
					$(SRC_DIR)/instruction_base.cpp $(INC_DIR)/instruction_base.hpp \
					$(SRC_DIR)/instruction_arg.cpp $(INC_DIR)/instruction_arg.hpp \
					$(SRC_DIR)/bus.cpp $(INC_DIR)/bus.hpp \
					$(SRC_DIR)/nop.cpp $(INC_DIR)/nop.hpp \
					$(SRC_DIR)/add.cpp $(INC_DIR)/add.hpp \
					$(SRC_DIR)/sub.cpp $(INC_DIR)/sub.hpp \
					$(SRC_DIR)/and.cpp $(INC_DIR)/and.hpp \
					$(SRC_DIR)/hlt.cpp $(INC_DIR)/hlt.hpp \
					$(SRC_DIR)/load.cpp $(INC_DIR)/load.hpp \
					$(SRC_DIR)/push.cpp $(INC_DIR)/push.hpp \
					$(SRC_DIR)/or.cpp $(INC_DIR)/or.hpp \
					$(SRC_DIR)/xor.cpp $(INC_DIR)/xor.hpp \
					$(SRC_DIR)/not.cpp $(INC_DIR)/not.hpp \
					$(SRC_DIR)/stor.cpp $(INC_DIR)/stor.hpp \
					$(SRC_DIR)/jmp.cpp $(INC_DIR)/jmp.hpp \
					$(SRC_DIR)/jz.cpp $(INC_DIR)/jz.hpp \
					$(SRC_DIR)/dup.cpp $(INC_DIR)/dup.hpp \
					$(SRC_DIR)/swap.cpp $(INC_DIR)/swap.hpp \
					$(SRC_DIR)/rol3.cpp $(INC_DIR)/rol3.hpp \
					$(SRC_DIR)/jnz.cpp $(INC_DIR)/jnz.hpp \
					$(SRC_DIR)/drop.cpp $(INC_DIR)/drop.hpp \
					$(SRC_DIR)/compl.cpp $(INC_DIR)/compl.hpp \
					$(SRC_DIR)/in.cpp $(INC_DIR)/in.hpp \
					$(SRC_DIR)/out.cpp $(INC_DIR)/out.hpp \
					$(SRC_DIR)/innum.cpp $(INC_DIR)/innum.hpp \
					$(SRC_DIR)/outnum.cpp $(INC_DIR)/outnum.hpp \
					$(SRC_DIR)/memory.cpp $(INC_DIR)/memory.hpp \
					$(SRC_DIR)/grammar.cpp $(INC_DIR)/grammar.hpp \
					$(SRC_DIR)/parser.cpp $(INC_DIR)/parser.hpp \
					$(SRC_DIR)/factory.cpp $(INC_DIR)/factory.hpp \
					$(SRC_DIR)/program_loader.cpp $(INC_DIR)/program_loader.hpp \
					$(SRC_DIR)/virtual_machine.cpp $(INC_DIR)/virtual_machine.hpp \
					$(SRC_DIR)/controller.cpp $(INC_DIR)/controller.hpp \
					$(SRC_DIR)/error.cpp $(INC_DIR)/error.hpp \
					$(SRC_DIR)/stack_overflow.cpp $(INC_DIR)/stack_overflow.hpp \
					$(SRC_DIR)/stack_underflow.cpp $(INC_DIR)/stack_underflow.hpp \
					$(SRC_DIR)/segmentation_fault.cpp $(INC_DIR)/segmentation_fault.hpp \
					$(SRC_DIR)/invalid_instruction.cpp $(INC_DIR)/invalid_instruction.hpp \
					$(SRC_DIR)/missing_argument.cpp $(INC_DIR)/missing_argument.hpp \
					$(SRC_DIR)/token_base.cpp $(INC_DIR)/token_base.hpp \
					$(SRC_DIR)/tnum.cpp $(INC_DIR)/tnum.hpp \
					$(SRC_DIR)/tstr.cpp $(INC_DIR)/tstr.hpp \
					$(SRC_DIR)/tcmd.cpp $(INC_DIR)/tcmd.hpp \
					$(SRC_DIR)/tdata.cpp $(INC_DIR)/tdata.hpp \

vala: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)


clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean vala