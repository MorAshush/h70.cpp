#include "mu_test.h"

#include "rational.hpp"


//class function add

BEGIN_TEST(add_rationals_equals)	

	Rational s(1, 3);
	Rational o(1, 3);
	s.add(o);

	ASSERT_THAT(s.get_numerator() == 2);
	ASSERT_THAT(s.get_denumerator() == 3);	

END_TEST

/*
BEGIN_TEST(add_rationals_when_self_denum_contains_the_other_denum)
	
	Rational s(1, 6);
	Rational o(1, 2);
	Rational r = s.add(o);

	ASSERT_THAT(r.get_numerator() == 4);
	ASSERT_THAT(r.get_denumerator() == 6);

END_TEST

BEGIN_TEST(add_rationals_when_other_denum_contains_the_self_denum)	
	
	Rational s(1, 3);
	Rational o(1, 6);
	Rational r = s.add(o);

	ASSERT_THAT(r.get_numerator() == 3);
	ASSERT_THAT(r.get_denumerator() == 6);

END_TEST

test with big rationals
test with negative rationals
test when each one is negative


//class function add with int


END_TEST

BEGIN_TEST(add_int_when_zero)

END_TEST

BEGIN_TEST(add_int_when_int_is_one)

END_TEST

BEGIN_TEST(add_int_when_int_is_big_number)

END_TEST

BEGIN_TEST(add_int_when_positive_self_and_negative_int)

END_TEST

BEGIN_TEST(add_int_when_negative_self_and_positive_int)

END_TEST

BEGIN_TEST(add_int_when_negative_self_and_negative_int)

END_TEST



//class function substruct

BEGIN_TEST(substruct_rationals_equals)	
	
	Rational s(1, 3);
	Rational o(1, 3);
	Rational r = s.substruct(o);

	ASSERT_THAT(r.get_numerator() == 0);
	ASSERT_THAT(r.get_denumerator() == 3);
	

END_TEST

BEGIN_TEST(substruct_rationals_when_self_denum_contains_the_other_denum)

	Rational s(5, 9);
	Rational o(1, 3);
	Rational r = s.substruct(o);

	ASSERT_THAT(r.get_numerator() == 2);
	ASSERT_THAT(r.get_denumerator() == 9);	
	

END_TEST

BEGIN_TEST(substruct_rationals_when_other_denum_contains_the_self_denum)

	Rational s(4, 6);
	Rational o(5, 18);
	Rational r = s.substruct(o);

	ASSERT_THAT(r.get_numerator() == 7);
	ASSERT_THAT(r.get_denumerator() == 18);	

END_TEST


BEGIN_TEST(substruct_when_self_smaller_then_other)

	Rational s(1, 6);
	Rational o(5, 6);
	Rational r = s.substruct(o);

	ASSERT_THAT(r.get_numerator() == -4);
	ASSERT_THAT(r.get_denumerator() == 6);

END_TEST

test with big rationals
test with negative rationals
test when each one is negative


//class functions substruct with int

BEGIN_TEST(substruct_int_when_int_is_zero)

END_TEST

BEGIN_TEST(substruct_int_when_int_is_big_number)

END_TEST

BEGIN_TEST(substruct_int_when_positive_self_and_negative_int)

END_TEST

BEGIN_TEST(substruct_int_when_negative_self_and_positive_int)

END_TEST

BEGIN_TEST(substruct_int_when_both_self_and_int_negative)

END_TEST



class function multiply:

BEGIN_TEST(multiply_when_self_rational_is_zero)

	Rational s(0, 6);
	Rational o(5, 7);
	Rational r = s.multiply(o);

	ASSERT_THAT(r.get_numerator() == 0);
	ASSERT_THAT(r.get_denumerator() == 42);

END_TEST

BEGIN_TEST(multiply_when_other_rational_is_zero)

	Rational s(12, 3);
	Rational o(0, 20);
	Rational r = s.multiply(o);

	ASSERT_THAT(r.get_numerator() == 0);
	ASSERT_THAT(r.get_denumerator() == 60);


END_TEST

BEGIN_TEST(multiply_when_both_are_zero)

	Rational s(0, 12);
	Rational o(0, 20);
	Rational r = s.multiply(o);

	ASSERT_THAT(r.get_numerator() == 0);
	ASSERT_THAT(r.get_denumerator() == 240);

END_TEST

BEGIN_TEST(multiply_when_self_rational_is_one)

	Rational s(1, 12);
	Rational o(10, 20);
	Rational r = s.multiply(o);

	ASSERT_THAT(r.get_numerator() == 10);
	ASSERT_THAT(r.get_denumerator() == 240);


END_TEST

BEGIN_TEST(multiply_when_other_rational_is_one)

	Rational s(14, 12);
	Rational o(1, 20);
	Rational r = s.multiply(o);

	ASSERT_THAT(r.get_numerator() == 14);
	ASSERT_THAT(r.get_denumerator() == 240);


END_TEST

BEGIN_TEST(multiply_when_both_are_one)

	Rational s(1, 12);
	Rational o(1, 20);
	Rational r = s.multiply(o);

	ASSERT_THAT(r.get_numerator() == 1);
	ASSERT_THAT(r.get_denumerator() == 240);


END_TEST

BEGIN_TEST(multiply_when_self_rational_numerator_is_negative)

	Rational s(-3, 12);
	Rational o(15, 20);
	Rational r = s.multiply(o);

	ASSERT_THAT(r.get_numerator() == -45);
	ASSERT_THAT(r.get_denumerator() == 240);

END_TEST

BEGIN_TEST(multiply_when_other_rational_numerator_is_negative)

	Rational s(3, 12);
	Rational o(-12, 20);
	Rational r = s.multiply(o);

	ASSERT_THAT(r.get_numerator() == -36);
	ASSERT_THAT(r.get_denumerator() == 240);

END_TEST

BEGIN_TEST(multiply_when_both_are_negative)

	Rational s(-3, 10);
	Rational o(-15, 20);
	Rational r = s.multiply(o);

	ASSERT_THAT(r.get_numerator() == 45);
	ASSERT_THAT(r.get_denumerator() == 200);
END_TEST

BEGIN_TEST(multiply_with_big_rationals)

	Rational s(550, 2040);
	Rational o(1560, 1234);
	Rational r = s.multiply(o);

	ASSERT_THAT(r.get_numerator() == 858000);
	ASSERT_THAT(r.get_denumerator() == 2517360);

END_TEST

test also with negative denumerator for each,
test with self is negative in both numerator and denumerator, 
same for the other rational,
test the same last two but with a negative second rational


//class function multiply with int:

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


//class function divide;

BEGIN_TEST(divide_when_self_rational_is_zero)

	Rational s(0, 20);
	Rational o(15, 34);
	Rational r = s.divide(o);

	ASSERT_THAT(r.get_numerator() == 0);
	ASSERT_THAT(r.get_denumerator() == 300);
	ASSERT_THAT(r.get_numerator() <= o.get_numerator());

END_TEST

BEGIN_TEST(divide_when_self_rational_is_one)

	Rational s(1, 13);
	Rational o(15, 34);
	Rational r = s.divide(o);

	ASSERT_THAT(r.get_numerator() == 34);
	ASSERT_THAT(r.get_denumerator() == 195);

END_TEST

BEGIN_TEST(divide_when_other_rational_is_one)

	Rational s(5, 13);
	Rational o(1, 10);
	Rational r = s.divide(o);

	ASSERT_THAT(r.get_numerator() == 50);
	ASSERT_THAT(r.get_denumerator() == 13);

END_TEST

BEGIN_TEST(divide_when_both_are_one)

	Rational s(1, 13);
	Rational o(1, 10);
	Rational r = s.divide(o);

	ASSERT_THAT(r.get_numerator() == 10);
	ASSERT_THAT(r.get_denumerator() == 13);


END_TEST

BEGIN_TEST(divide_when_self_rational_numerator_is_negative)

	Rational s(-5, 13);
	Rational o(8, 10);
	Rational r = s.divide(o);

	ASSERT_THAT(r.get_numerator() == -50);
	ASSERT_THAT(r.get_denumerator() == 104);

END_TEST

BEGIN_TEST(divide_when_other_rational_numerator_is_negative)

	Rational s(5, 13);
	Rational o(-28, 100);
	Rational r = s.divide(o);

	ASSERT_THAT(r.get_numerator() == 500);
	ASSERT_THAT(r.get_denumerator() == -364);

END_TEST


test also with negative denumerator for each
test with self is negative in both numerator and denumerator, 
same for the other rational,
test_when_both_are_negative,
divide_with_big_rationals,




//class function divide with int:


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



//class function reduce:


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
	/*TEST(add_rationals_when_self_denum_contains_the_other_denum)
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
*/

END_SUITE

