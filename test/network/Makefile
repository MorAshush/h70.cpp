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

TARGET = utest
OBJS = utest.o $(SRC_DIR)/server_socket.o \
				$(SRC_DIR)/client_socket.o \
				$(SRC_DIR)/tcp_server.o \
				$(SRC_DIR)/selector_base.o \
				$(SRC_DIR)/select_selector.o \
				$(SRC_DIR)/handler.o \
				$(SRC_DIR)/client_handler.o \
				$(SRC_DIR)/random_guess.o \
				$(SRC_DIR)/address_class.o \			

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

utest : utest.cpp $(SRC_DIR)/server_socket.cpp $(INC_DIR)/server_socket.hpp \
					$(SRC_DIR)/client_socket.cpp $(INC_DIR)/client_socket.hpp \
					$(SRC_DIR)/tcp_server.cpp $(INC_DIR)/tcp_server.hpp \
					$(SRC_DIR)/selector_base.cpp $(INC_DIR)/selector_base.hpp \
					$(SRC_DIR)/select_selector.cpp $(INC_DIR)/select_selector.hpp \
					$(SRC_DIR)/handler.cpp $(INC_DIR)/handler.hpp \
					$(SRC_DIR)/client_handler.cpp $(INC_DIR)/client_handler.hpp \
					$(SRC_DIR)/random_guess.cpp $(INC_DIR)/random_guess.hpp \
					$(SRC_DIR)/address_class.cpp $(INC_DIR)/address_class.hpp \
					

vala: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)


clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean vala