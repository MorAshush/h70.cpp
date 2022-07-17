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

INC_DIR = ../../inc/network
INC_DIR_2 = ../../inc/threads
SRC_DIR = ../../src/network
SRC_DIR_2 = ../../src/threads

TARGET = utest
OBJS = utest.o $(SRC_DIR)/server_socket.o \
				$(SRC_DIR)/client_socket.o \
				$(SRC_DIR)/tcp_server.o \
				$(SRC_DIR)/selector_base.o \
				$(SRC_DIR)/select_selector.o \
				$(SRC_DIR)/handler.o \
				$(SRC_DIR)/request_handler.o \
				$(SRC_DIR)/address_class.o \
				$(SRC_DIR_2)/semaphore.o\
				$(SRC_DIR_2)/semaphore_error.o\
				$(SRC_DIR)/processor.o \
				$(SRC_DIR)/protocol.o \
				$(SRC_DIR)/command.o \
				$(SRC_DIR)/supported_cmds.o \
				$(SRC_DIR)/all_commands.o \

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

utest : utest.cpp \
$(INC_DIR_2)/thread_safe_queue.hpp \
$(SRC_DIR_2)/semaphore.cpp \
$(INC_DIR_2)/semaphore.hpp \
$(SRC_DIR_2)/semaphore_error.cpp \
$(INC_DIR_2)/semaphore_error.hpp \
$(SRC_DIR)/server_socket.cpp \
$(INC_DIR)/server_socket.hpp \
$(SRC_DIR)/client_socket.cpp \
$(INC_DIR)/client_socket.hpp \
$(SRC_DIR)/tcp_server.cpp \
$(INC_DIR)/tcp_server.hpp \
$(SRC_DIR)/selector_base.cpp \
$(INC_DIR)/selector_base.hpp \
$(SRC_DIR)/select_selector.cpp \
$(INC_DIR)/select_selector.hpp \
$(SRC_DIR)/handler.cpp \
$(INC_DIR)/handler.hpp \
$(SRC_DIR)/request_handler.cpp \
$(INC_DIR)/request_handler.hpp \
$(SRC_DIR)/address_class.cpp \
$(INC_DIR)/address_class.hpp \
$(SRC_DIR)/processor.cpp \
$(INC_DIR)/processor.hpp \
$(SRC_DIR)/protocol.cpp \
$(INC_DIR)/protocol.hpp \
$(SRC_DIR)/command.cpp \
$(INC_DIR)/command.hpp \
$(INC_DIR)/definitions.hpp \
$(SRC_DIR)/supported_cmds.cpp \
$(INC_DIR)/supported_cmds.hpp \
$(SRC_DIR)/all_commands.cpp \
$(INC_DIR)/all_commands.hpp \

vala: $(TARGET)
	valgrind --leak-check=full --track-origins=yes --log-file=logValgrind01.txt ./$(TARGET)
	valgrind --tool=helgrind --log-file=loghelgrind01.txt ./$(TARGET)
	valgrind --tool=drd --log-file=logdrd01.txt ./$(TARGET)


clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean vala