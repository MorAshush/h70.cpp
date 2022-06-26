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

INC_DIR = ../../inc/firmware_stack_machine
SRC_DIR = ../../src/firmware_stack_machine

TARGET = utest

utest : utest.cpp $(SRC_DIR)/functions.o $(SRC_DIR)/stack.o $(SRC_DIR)/bus.o $(SRC_DIR)/memory.o $(SRC_DIR)/mapper.o $(SRC_DIR)/controller.o $(SRC_DIR)/error.o $(SRC_DIR)/segmentation_fault.o $(SRC_DIR)/parser.o
					
OBJS = utest.o $(SRC_DIR)/functions.o $(SRC_DIR)/stack.o $(SRC_DIR)/bus.o $(SRC_DIR)/memory.o $(SRC_DIR)/mapper.o $(SRC_DIR)/controller.o $(SRC_DIR)/error.o $(SRC_DIR)/segmentation_fault.o $(SRC_DIR)/parser.o

rr: $(OBJS)

XYZ = $(SRC_DIR)/functions.o \
		$(SRC_DIR)/stack.o \
		$(SRC_DIR)/bus.o \
		$(SRC_DIR)/memory.o \
		$(SRC_DIR)/mapper.o \
		$(SRC_DIR)/controller.o \
		$(SRC_DIR)/error.o \
		$(SRC_DIR)/segmentation_fault.o \

all: $(TARGET)

check: $(TARGET)
	./$(TARGET)

vala: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)


clean:
	@$(RM) $(TARGET) $(OBJS) utest.o

.PHONY: all check clean vala