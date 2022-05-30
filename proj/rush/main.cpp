
#include "game.hpp"


int main(int argc, char* argv[])
{
	game::Game newGame(argv[1]);
	newGame.start();
}