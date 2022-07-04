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

INC_DIR = ../../inc/network
SRC_DIR = ../../src/network

TARGET = run_client
OBJS = run_client.o $(SRC_DIR)/client_socket.o $(SRC_DIR)/address_class.o $(SRC_DIR)/handler.o $(SRC_DIR)/client_handler.o

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

run_client : run_client.cpp $(SRC_DIR)/client_socket.cpp $(INC_DIR)/client_socket.hpp \
							$(SRC_DIR)/address_class.cpp $(INC_DIR)/address_class.hpp \
							$(SRC_DIR)/handler.cpp $(INC_DIR)/handler.hpp \
							$(SRC_DIR)/client_handler.cpp $(INC_DIR)/client_handler.hpp \

vala: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes


clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean vala