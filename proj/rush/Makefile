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

INC_DIR = ../../inc/rush
SRC_DIR = ../../src/rush

TARGET = main
OBJS = main.o $(SRC_DIR)/board.o $(SRC_DIR)/car.o $(SRC_DIR)/game.o

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

main : main.cpp $(SRC_DIR)/board.cpp $(INC_DIR)/board.hpp $(SRC_DIR)/car.cpp $(INC_DIR)/car.hpp $(SRC_DIR)/game.cpp $(INC_DIR)/game.hpp

vala: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET) level1.txt


clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean vala