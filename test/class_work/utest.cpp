#include "mu_test.h"

#include "rational.hpp"


//class function add

BEGIN_TEST(add_rationals_equals)	

	algebra::Rational s(1, 3);
	algebra::Rational o(1, 3);
	s.add(o);

	ASSERT_THAT(s.get_numerator() == 2);
	ASSERT_THAT(s.get_denumerator() == 3);	

END_TEST


BEGIN_TEST(add_rationals_when_self_denum_contains_the_other_denum)
	
	algebra::Rational s(1, 6);
	algebra::Rational o(1, 2);
	s.add(o);

	ASSERT_THAT(s.get_numerator() == 4);
	ASSERT_THAT(s.get_denumerator() == 6);

END_TEST

BEGIN_TEST(add_rationals_when_other_denum_contains_the_self_denum)	
	
	algebra::Rational s(1, 3);
	algebra::Rational o(1, 6);
	s.add(o);

	ASSERT_THAT(s.get_numerator() == 3);
	ASSERT_THAT(s.get_denumerator() == 6);

END_TEST
/*
test with big rationals
test with negative rationals
test when each one is negative
*/


//class function add with int


BEGIN_TEST(add_int_when_zero)
	
	algebra::Rational s(1, 6);
	int n = 3;
	s.add(n);

	ASSERT_THAT(s.get_numerator() == 19);
	ASSERT_THAT(s.get_denumerator() == 6);

END_TEST

BEGIN_TEST(add_int_when_int_is_one)

	algebra::Rational s(1, 6);
	int n = 1;
	s.add(n);

	ASSERT_THAT(s.get_numerator() == 7);
	ASSERT_THAT(s.get_denumerator() == 6);


END_TEST

BEGIN_TEST(add_int_when_int_is_big_number)

	algebra::Rational s(1, 3);
	int n = 1023;
	s.add(n);

	ASSERT_THAT(s.get_numerator() == 3069);
	ASSERT_THAT(s.get_denumerator() == 3);


END_TEST

BEGIN_TEST(add_int_when_positive_self_and_negative_int)

	algebra::Rational s(6, 8);
	int n = -3;
	s.add(n);

	ASSERT_THAT(s.get_numerator() == -18);
	ASSERT_THAT(s.get_denumerator() == 8);


END_TEST

BEGIN_TEST(add_int_when_negative_self_and_positive_int)

	algebra::Rational s(-6, 8);
	int n = 2;
	s.add(n);

	ASSERT_THAT(s.get_numerator() == 10);
	ASSERT_THAT(s.get_denumerator() == 8);

END_TEST

BEGIN_TEST(add_int_when_negative_self_and_negative_int)

	algebra::Rational s(-6, 8);
	int n = -3;
	s.add(n);

	ASSERT_THAT(s.get_numerator() == -30);
	ASSERT_THAT(s.get_denumerator() == 8);

END_TEST



//class function substruct

BEGIN_TEST(substruct_rationals_equals)	
	
	algebra::Rational s(1, 3);
	algebra::Rational o(1, 3);
	s.substruct(o);

	ASSERT_THAT(s.get_numerator() == 0);
	ASSERT_THAT(s.get_denumerator() == 3);
	

END_TEST

BEGIN_TEST(substruct_rationals_when_self_denum_contains_the_other_denum)

	algebra::Rational s(5, 9);
	algebra::Rational o(1, 3);
	s.substruct(o);

	ASSERT_THAT(s.get_numerator() == 2);
	ASSERT_THAT(s.get_denumerator() == 9);	
	

END_TEST

BEGIN_TEST(substruct_rationals_when_other_denum_contains_the_self_denum)

	algebra::Rational s(4, 6);
	algebra::Rational o(5, 18);
	s.substruct(o);

	ASSERT_THAT(s.get_numerator() == 7);
	ASSERT_THAT(s.get_denumerator() == 18);	

END_TEST


BEGIN_TEST(substruct_when_self_smaller_then_other)

	algebra::Rational s(1, 6);
	algebra::Rational o(5, 6);
	s.substruct(o);

	ASSERT_THAT(s.get_numerator() == -4);
	ASSERT_THAT(s.get_denumerator() == 6);

END_TEST
/*
test with big rationals
test with negative rationals
test when each one is negative
*/

//class functions substruct with int

BEGIN_TEST(substruct_int_when_int_is_zero)

	algebra::Rational s(1, 6);
	int n = 0;
	s.substruct(n);

	ASSERT_THAT(s.get_numerator() == 1);
	ASSERT_THAT(s.get_denumerator() == 6);


END_TEST

BEGIN_TEST(substruct_int_when_int_is_big_number)

	algebra::Rational s(567, 230);
	int n = 45005;
	s.substruct(n);

	ASSERT_THAT(s.get_numerator() == -10350583);
	ASSERT_THAT(s.get_denumerator() == 230);

END_TEST

BEGIN_TEST(substruct_int_when_positive_self_and_negative_int)

	algebra::Rational s(10, 12);
	int n = -4;
	s.substruct(n);

	ASSERT_THAT(s.get_numerator() == -38);
	ASSERT_THAT(s.get_denumerator() == 12);

END_TEST

BEGIN_TEST(substruct_int_when_negative_self_and_positive_int)

	algebra::Rational s(-41, 20);
	int n = 2;
	s.substruct(n);

	ASSERT_THAT(s.get_numerator() == -81);
	ASSERT_THAT(s.get_denumerator() == 20);

END_TEST

BEGIN_TEST(substruct_int_when_both_self_and_int_negative)

	algebra::Rational s(-41, 20);
	int n = -2;
	s.substruct(n);

	ASSERT_THAT(s.get_numerator() == -1);
	ASSERT_THAT(s.get_denumerator() == 6);

END_TEST



//class function multiply:

BEGIN_TEST(multiply_when_self_rational_is_zero)

	algebra::Rational s(0, 6);
	algebra::Rational o(5, 7);
	s.multiply(o);

	ASSERT_THAT(s.get_numerator() == 0);
	ASSERT_THAT(s.get_denumerator() == 42);

END_TEST

BEGIN_TEST(multiply_when_other_rational_is_zero)

	algebra::Rational s(12, 3);
	algebra::Rational o(0, 20);
	s.multiply(o);

	ASSERT_THAT(s.get_numerator() == 0);
	ASSERT_THAT(s.get_denumerator() == 60);


END_TEST

BEGIN_TEST(multiply_when_both_are_zero)

	algebra::Rational s(0, 12);
	algebra::Rational o(0, 20);
	s.multiply(o);

	ASSERT_THAT(s.get_numerator() == 0);
	ASSERT_THAT(s.get_denumerator() == 240);

END_TEST

BEGIN_TEST(multiply_when_self_rational_is_one)

	algebra::Rational s(1, 12);
	algebra::Rational o(10, 20);
	s.multiply(o);

	ASSERT_THAT(s.get_numerator() == 10);
	ASSERT_THAT(s.get_denumerator() == 240);


END_TEST

BEGIN_TEST(multiply_when_other_rational_is_one)

	algebra::Rational s(14, 12);
	algebra::Rational o(1, 20);
	s.multiply(o);

	ASSERT_THAT(s.get_numerator() == 14);
	ASSERT_THAT(s.get_denumerator() == 240);


END_TEST

BEGIN_TEST(multiply_when_both_are_one)

	algebra::Rational s(1, 12);
	algebra::Rational o(1, 20);
	s.multiply(o);


	ASSERT_THAT(s.get_numerator() == 1);
	ASSERT_THAT(s.get_denumerator() == 240);


END_TEST

BEGIN_TEST(multiply_when_self_rational_numerator_is_negative)

	algebra::Rational s(-3, 12);
	algebra::Rational o(15, 20);
	s.multiply(o);


	ASSERT_THAT(s.get_numerator() == -45);
	ASSERT_THAT(s.get_denumerator() == 240);

END_TEST

BEGIN_TEST(multiply_when_other_rational_numerator_is_negative)

	algebra::Rational s(3, 12);
	algebra::Rational o(-12, 20);
	s.multiply(o);


	ASSERT_THAT(s.get_numerator() == -36);
	ASSERT_THAT(s.get_denumerator() == 240);

END_TEST

BEGIN_TEST(multiply_when_both_are_negative)

	algebra::Rational s(-3, 10);
	algebra::Rational o(-15, 20);
	s.multiply(o);


	ASSERT_THAT(s.get_numerator() == 45);
	ASSERT_THAT(s.get_denumerator() == 200);
END_TEST

BEGIN_TEST(multiply_with_big_rationals)

	algebra::Rational s(550, 2040);
	algebra::Rational o(1560, 1234);
	s.multiply(o);


	ASSERT_THAT(s.get_numerator() == 858000);
	ASSERT_THAT(s.get_denumerator() == 2517360);

END_TEST
/*
test also with negative denumerator for each,
test with self is negative in both numerator and denumerator, 
same for the other rational,
test the same last two but with a negative second rational
*/

//class function multiply with int:
/*
BEGIN_TEST(multiply_int_when_int_is_zero)

END_TEST

BEGIN_TEST(multiply_int_when_int_is_one)

END_TEST

BEGIN_TEST(multiply_int_when_int_is_positive_big_number)

END_TEST

BEGIN_TEST(multiply_int_when_int_is_negative)

END_TEST

BEGIN_TEST(multiply_int_when_self_positive_int_negative)

END_TEST

BEGIN_TEST(multiply_int_when_self_negative_int_positive)

END_TEST

BEGIN_TEST(multiply_int_when_both_self_and_int_negative)

END_TEST
*/

//class function divide;

BEGIN_TEST(divide_when_self_rational_is_zero)

	algebra::Rational s(0, 20);
	algebra::Rational o(15, 34);
	s.divide(o);

	ASSERT_THAT(s.get_numerator() == 0);
	ASSERT_THAT(s.get_denumerator() == 300);
	ASSERT_THAT(s.get_numerator() <= o.get_numerator());

END_TEST

BEGIN_TEST(divide_when_self_rational_is_one)

	algebra::Rational s(1, 13);
	algebra::Rational o(15, 34);
	s.divide(o);

	ASSERT_THAT(s.get_numerator() == 34);
	ASSERT_THAT(s.get_denumerator() == 195);

END_TEST

BEGIN_TEST(divide_when_other_rational_is_one)

	algebra::Rational s(5, 13);
	algebra::Rational o(1, 10);
	s.divide(o);

	ASSERT_THAT(s.get_numerator() == 50);
	ASSERT_THAT(s.get_denumerator() == 13);

END_TEST

BEGIN_TEST(divide_when_both_are_one)

	algebra::Rational s(1, 13);
	algebra::Rational o(1, 10);
	s.divide(o);

	ASSERT_THAT(s.get_numerator() == 10);
	ASSERT_THAT(s.get_denumerator() == 13);


END_TEST

BEGIN_TEST(divide_when_self_rational_numerator_is_negative)

	algebra::Rational s(-5, 13);
	algebra::Rational o(8, 10);
	s.divide(o);

	ASSERT_THAT(s.get_numerator() == -50);
	ASSERT_THAT(s.get_denumerator() == 104);

END_TEST

BEGIN_TEST(divide_when_other_rational_numerator_is_negative)

	algebra::Rational s(5, 13);
	algebra::Rational o(-28, 100);
	s.divide(o);

	ASSERT_THAT(s.get_numerator() == 500);
	ASSERT_THAT(s.get_denumerator() == -364);

END_TEST

/*
test also with negative denumerator for each
test with self is negative in both numerator and denumerator, 
same for the other rational,
test_when_both_are_negative,
divide_with_big_rationals,
*/



//class function divide with int:

/*
BEGIN_TEST(divide_int_when_int_is_one)

END_TEST

BEGIN_TEST(divide_int_when_both_self_and_int_positive)

END_TEST

BEGIN_TEST(divide_int_when_self_positive_int_negative)

END_TEST

BEGIN_TEST(divide_int_when_self_negative_int_positive)

END_TEST

BEGIN_TEST(divide_int_when_both_self_and_int_negative)

END_TEST
*/


//class function reduce:

/*
BEGIN_TEST(reduce_when_self_numerator_is_one)

END_TEST

BEGIN_TEST(reduce_when_self_denumerator_is_one)

END_TEST

BEGIN_TEST(reduce_when_self_numerator_is_zero)

END_TEST

BEGIN_TEST(reduce_when_self_numerator_is_negative)

END_TEST

BEGIN_TEST(reduce_when_self_denumerator_is_negative)

END_TEST

BEGIN_TEST(reduce_when_self_is_unreducable)

END_TEST

BEGIN_TEST(reduce_when_self_numerator_denomerator_are_big_numbers)

END_TEST

BEGIN_TEST(reduce_when_self_numerator_denomerator_are_small_numbers)

END_TEST

*/

BEGIN_SUITE(Its what you learn after you know it all that counts)

	TEST(add_rationals_equals)
	TEST(add_rationals_when_self_denum_contains_the_other_denum)
	TEST(add_rationals_when_other_denum_contains_the_self_denum)

	TEST(substruct_rationals_equals)
	TEST(substruct_rationals_equals)
	TEST(substruct_rationals_when_self_denum_contains_the_other_denum)
	TEST(substruct_rationals_when_other_denum_contains_the_self_denum)
	TEST(substruct_when_self_smaller_then_other)

	TEST(multiply_when_self_rational_is_zero)
	TEST(multiply_when_other_rational_is_zero)
	TEST(multiply_when_both_are_zero)
	TEST(multiply_when_self_rational_is_one)
	TEST(multiply_when_other_rational_is_one)
	TEST(multiply_when_both_are_one)
	TEST(multiply_when_self_rational_numerator_is_negative)
	TEST(multiply_when_other_rational_numerator_is_negative)
	TEST(multiply_when_both_are_negative)
	TEST(multiply_with_big_rationals)

	TEST(divide_when_self_rational_is_zero)
	TEST(divide_when_self_rational_is_one)
	TEST(divide_when_other_rational_is_one)
	TEST(divide_when_both_are_one)
	TEST(divide_when_self_rational_numerator_is_negative)
	TEST(divide_when_other_rational_numerator_is_negative)

	TEST(add_int_when_zero)
	TEST(add_int_when_int_is_one)
	TEST(add_int_when_int_is_big_number)
	TEST(add_int_when_positive_self_and_negative_int)
	TEST(add_int_when_negative_self_and_positive_int)
	TEST(add_int_when_negative_self_and_negative_int)

	TEST(substruct_int_when_int_is_zero)
	TEST(substruct_int_when_int_is_big_number)
	TEST(substruct_int_when_positive_self_and_negative_int)
	TEST(substruct_int_when_negative_self_and_positive_int)
	TEST(substruct_int_when_both_self_and_int_negative)
	/*
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
*/

END_SUITE

