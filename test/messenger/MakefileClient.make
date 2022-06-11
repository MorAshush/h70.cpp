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

INC_DIR = ../../inc/messenger
SRC_DIR = ../../src/messenger

TARGET = run_client
OBJS = run_client.o $(SRC_DIR)/udp_socket_output.o 

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

run_client : run_client.cpp $(SRC_DIR)/udp_socket_output.cpp $(INC_DIR)/udp_socket_output.hpp $(SRC_DIR)/text_output.cpp $(INC_DIR)/text_output.hpp

vala: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes


clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean vala