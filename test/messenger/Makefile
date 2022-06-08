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

TARGET = utest
OBJS = utest.o $(SRC_DIR)/text_transformer.o $(SRC_DIR)/uppercase.o $(SRC_DIR)/lowercase.o $(SRC_DIR)/rot13.o $(SRC_DIR)/text_input.o $(SRC_DIR)/file_input.o \
				$(SRC_DIR)/keyboard.o $(SRC_DIR)/censor.o $(SRC_DIR)/file_output.o $(SRC_DIR)/screen.o $(SRC_DIR)/text_output.o $(SRC_DIR)/messenger.o \
				$(SRC_DIR)/udp_socket_output.o $(SRC_DIR)/udp_socket_input.o $(SRC_DIR)/multi_transformer.o

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

utest : utest.cpp $(SRC_DIR)/text_transformer.cpp $(INC_DIR)/text_transformer.hpp $(SRC_DIR)/uppercase.cpp $(INC_DIR)/uppercase.hpp \
		$(SRC_DIR)/lowercase.cpp $(INC_DIR)/lowercase.hpp $(SRC_DIR)/rot13.cpp $(INC_DIR)/rot13.hpp $(SRC_DIR)/text_input.cpp $(INC_DIR)/text_input.hpp \
		$(SRC_DIR)/file_input.cpp $(INC_DIR)/file_input.hpp $(SRC_DIR)/keyboard.cpp $(INC_DIR)/keyboard.hpp $(SRC_DIR)/censor.cpp \
		$(INC_DIR)/censor.hpp $(SRC_DIR)/text_output.cpp $(INC_DIR)/text_output.hpp $(SRC_DIR)/file_output.cpp $(INC_DIR)/file_output.hpp $(SRC_DIR)/screen.cpp \
		$(INC_DIR)/screen.hpp $(SRC_DIR)/messenger.cpp $(INC_DIR)/messenger.hpp $(SRC_DIR)/udp_socket_output.cpp $(INC_DIR)/udp_socket_output.hpp \
		$(SRC_DIR)/udp_socket_input.cpp $(INC_DIR)/udp_socket_input.hpp $(SRC_DIR)/multi_transformer.cpp $(INC_DIR)/multi_transformer.hpp

vala: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes


clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean vala