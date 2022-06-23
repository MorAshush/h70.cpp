#include "mu_test.h"

#include "game.hpp"
#include "car.hpp"
#include "board.hpp"



/*
BEGIN_TEST(test)	

	game::Board b;
	b.print();

	game::Coordinates location1 = {2, 4};
	game::Coordinates location2 = {1, 3};
	game::Coordinates location3 = {3, 0};

	b.place_car('Y', 2, 1, location1);
	b.place_car('R', 3, 1, location2);
	b.place_car('G', 3, 0, location3);

	b.print();

	ASSERT_PASS();	

END_TEST
*/

BEGIN_TEST(game_start_test)

	game::Game g("level2.txt");
	g.start();

	ASSERT_PASS();

END_TEST

BEGIN_SUITE(tests)

//	TEST(test)
	TEST(game_start_test)

END_SUITE