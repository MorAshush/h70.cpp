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

BEGIN_TEST(add_rationals_when_passing_positive_int)	
	
	algebra::Rational s(1, 3);
	int n = 6;
	s.add(n);

	ASSERT_THAT(s.get_numerator() == 19);
	ASSERT_THAT(s.get_denumerator() == 3);

END_TEST

BEGIN_TEST(add_rationals_when_passing_negative_int)	
	
	algebra::Rational s(1, 3);
	int n = -6;
	s.add(n);

	ASSERT_THAT(s.get_numerator() == -17);
	ASSERT_THAT(s.get_denumerator() == 3);

END_TEST

/*
test with big rationals
test with negative rationals
test when each one is negative
*/

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

BEGIN_TEST(substruct_when_passing_positive_int)

	algebra::Rational s(1, 6);
	int n = 5;
	s.substruct(n);

	ASSERT_THAT(s.get_numerator() == -29);
	ASSERT_THAT(s.get_denumerator() == 6);

END_TEST

BEGIN_TEST(substruct_when_passing_negative_int)

	algebra::Rational s(1, 6);
	int n = -5;
	s.substruct(n);

	ASSERT_THAT(s.get_numerator() == 31);
	ASSERT_THAT(s.get_denumerator() == 6);

END_TEST
/*
test with big rationals
test with negative rationals
test when each one is negative
*/

//class function multiply by rational:

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

BEGIN_TEST(multiply_when_passing_an_int)

	algebra::Rational s(12, 3);
	int n = 20;
	s.multiply(n);

	ASSERT_THAT(s.get_numerator() == 240);
	ASSERT_THAT(s.get_denumerator() == 3);


END_TEST
/*
test also with negative denumerator for each,
test with self is negative in both numerator and denumerator, 
test the same last two but with a negative second rational
*/

//class function divide;

BEGIN_TEST(divide_when_self_rational_is_zero)

	algebra::Rational s(0, 20);
	algebra::Rational o(15, 34);
	s.divide(o);

	ASSERT_THAT(s.get_numerator() == 0);
	ASSERT_THAT(s.get_denumerator() == 300);

END_TEST

BEGIN_TEST(divide_when_self_rational_is_one)

	algebra::Rational s(1, 13);
	algebra::Rational o(2, 4);
	s.divide(o);

	ASSERT_THAT(s.get_numerator() == 4);
	ASSERT_THAT(s.get_denumerator() == 26);

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

	ASSERT_THAT(s.get_numerator() == -500);
	ASSERT_THAT(s.get_denumerator() == 364);

END_TEST

BEGIN_TEST(divide_when_passing_a_positive_int)

	algebra::Rational s(5, 10);
	int n = 5;
	s.divide(n);

	ASSERT_THAT(s.get_numerator() == 5);
	ASSERT_THAT(s.get_denumerator() == 50);

END_TEST

BEGIN_TEST(divide_when_passing_a_negative_int)

	algebra::Rational s(5, 10);
	int n = -10;
	s.divide(n);

	ASSERT_THAT(s.get_numerator() == -5);
	ASSERT_THAT(s.get_denumerator() == 100);

END_TEST

/*
test also with negative denumerator for each
test with self is negative in both numerator and denumerator, 
same for the other rational,
test_when_both_are_negative,
divide_with_big_rationals,
*/


//class function reduce:


BEGIN_TEST(reduce_when_self_numerator_is_one)

	algebra::Rational s(1, 13);

	s.reduce();

	ASSERT_THAT(s.get_numerator() == 1);
	ASSERT_THAT(s.get_denumerator() == 13);

END_TEST

BEGIN_TEST(reduce_when_self_denumerator_is_one)

	algebra::Rational s(4, 1);

	s.reduce();

	ASSERT_THAT(s.get_numerator() == 4);
	ASSERT_THAT(s.get_denumerator() == 1);

END_TEST

BEGIN_TEST(reduce_when_self_numerator_is_zero)

	algebra::Rational s(0, 13);

	s.reduce();

	ASSERT_THAT(s.get_numerator() == 0);
	ASSERT_THAT(s.get_denumerator() == 13);

END_TEST

BEGIN_TEST(reduce_when_self_reducable_and_negative)

	algebra::Rational s(-28, 28);

	s.reduce();

	ASSERT_THAT(s.get_numerator() == -1);
	ASSERT_THAT(s.get_denumerator() == 1);

END_TEST

BEGIN_TEST(reduce_when_self_reducable_and_positive)

	algebra::Rational s(21, 35);

	s.reduce();

	ASSERT_THAT(s.get_numerator() == 3);
	ASSERT_THAT(s.get_denumerator() == 5);

END_TEST

BEGIN_TEST(reduce_when_self_unreducable_and_negative)

	algebra::Rational s(-23, 28);

	s.reduce();

	ASSERT_THAT(s.get_numerator() == -23);
	ASSERT_THAT(s.get_denumerator() == 28);

END_TEST

BEGIN_TEST(reduce_when_self_unreducable_and_positive)

	algebra::Rational s(23, 35);

	s.reduce();

	ASSERT_THAT(s.get_numerator() == 23);
	ASSERT_THAT(s.get_denumerator() == 35);

END_TEST

BEGIN_TEST(reduce_when_self_reducable_and_negative_big_rational)

	algebra::Rational s(-285000, 1202350);

	s.reduce();

	ASSERT_THAT(s.get_numerator() == -5700);
	ASSERT_THAT(s.get_denumerator() == 24047);

END_TEST

BEGIN_TEST(reduce_when_self_reducable_and_positive_big_rational)

	algebra::Rational s(2130, 3563680);

	s.reduce();

	ASSERT_THAT(s.get_numerator() == 213);
	ASSERT_THAT(s.get_denumerator() == 356368);

END_TEST


// class function operator *=

BEGIN_TEST(operator_mult_on_self_by_zero)

	algebra::Rational s(5, 9);
	algebra::Rational o(0);
	s *= o;

	ASSERT_THAT(s.get_numerator() == 0);

END_TEST

BEGIN_TEST(operator_mult_on_self_by_positive_rational)

	algebra::Rational s(5, 9);
	algebra::Rational o(4,2);
	s *= o;

	ASSERT_THAT(s.get_numerator() == 20);
	ASSERT_THAT(s.get_denumerator() == 18);

END_TEST

BEGIN_TEST(operator_mult_on_self_by_negative_rational)

	algebra::Rational s(5, 9);
	algebra::Rational o(-3,2);
	s *= o;

	ASSERT_THAT(s.get_numerator() == -15);
	ASSERT_THAT(s.get_denumerator() == 18);

END_TEST

BEGIN_TEST(operator_mult_on_self_by_positive_int)

	algebra::Rational s(5, 9);
	int n = 4;
	s *= n;

	ASSERT_THAT(s.get_numerator() == 20);
	ASSERT_THAT(s.get_denumerator() == 9);

END_TEST

BEGIN_TEST(operator_mult_on_self_by_negative_int)

	algebra::Rational s(5, 9);
	int n = -4;
	s *= n;

	ASSERT_THAT(s.get_numerator() == -20);
	ASSERT_THAT(s.get_denumerator() == 9);


END_TEST


//class function operator +=

BEGIN_TEST(operator_add_on_self_with_rational_zero)

	algebra::Rational s(5, 9);
	algebra::Rational o(0);
	s += o;

	ASSERT_THAT(s.get_numerator() == 5);
	ASSERT_THAT(s.get_denumerator() == 9);

END_TEST

BEGIN_TEST(operator_add_on_self_with_one)

	algebra::Rational s(5, 9);
	algebra::Rational o(1,1);
	s += o;

	ASSERT_THAT(s.get_numerator() == 14);
	ASSERT_THAT(s.get_denumerator() == 9);

END_TEST

BEGIN_TEST(operator_add_on_self_with_negative_rational)

	algebra::Rational s(5, 9);
	algebra::Rational o(-2, 3);
	s += o;

	ASSERT_THAT(s.get_numerator() == -1);
	ASSERT_THAT(s.get_denumerator() == 9);

END_TEST

BEGIN_TEST(operator_add_on_self_with_positive_rational)

	algebra::Rational s(5, 9);
	algebra::Rational o(2, 3);
	s += o;

	ASSERT_THAT(s.get_numerator() == 11);
	ASSERT_THAT(s.get_denumerator() == 9);

END_TEST

BEGIN_TEST(operator_add_on_self_with_positive_int)

	algebra::Rational s(5, 9);
	int n = 2;

	s += n;

	ASSERT_THAT(s.get_numerator() == 23);
	ASSERT_THAT(s.get_denumerator() == 9);

END_TEST

BEGIN_TEST(operator_add_on_self_with_negative_int)

	algebra::Rational s(5, 9);
	int n = -2;

	s += n;

	ASSERT_THAT(s.get_numerator() == -13);
	ASSERT_THAT(s.get_denumerator() == 9);

END_TEST

//add tests with big numbers


//class function operator -=

BEGIN_TEST(operator_subtruct_on_self_with_one)

	algebra::Rational s(5, 9);
	algebra::Rational o(1, 1);
	s -= o;

	ASSERT_THAT(s.get_numerator() == -4);
	ASSERT_THAT(s.get_denumerator() == 9);


END_TEST

BEGIN_TEST(operator_subtruct_on_self_with_positive_rational)

	algebra::Rational s(5, 9);
	algebra::Rational o(2, 3);
	s -= o;

	ASSERT_THAT(s.get_numerator() == -1);
	ASSERT_THAT(s.get_denumerator() == 9);


END_TEST

BEGIN_TEST(operator_subtruct_on_self_with_negative_rational)

	algebra::Rational s(5, 9);
	algebra::Rational o(-2, 3);
	s -= o;

	ASSERT_THAT(s.get_numerator() == 11);
	ASSERT_THAT(s.get_denumerator() == 9);


END_TEST

BEGIN_TEST(operator_subtruct_on_self_with_equal_rational)

	algebra::Rational s(5, 9);
	algebra::Rational o(5, 9);
	s -= o;

	ASSERT_THAT(s.get_numerator() == 0);
	ASSERT_THAT(s.get_denumerator() == 9);

END_TEST

//add tests with big numbers


//class function operator /=

BEGIN_TEST(operator_divide_on_self_positive_by_positive_rational)

	algebra::Rational s(5, 9);
	algebra::Rational o(2, 5);
	s /= o;

	ASSERT_THAT(s.get_numerator() == 25);
	ASSERT_THAT(s.get_denumerator() == 18);

END_TEST

BEGIN_TEST(operator_divide_on_self_negative_by_positive_rational)

	algebra::Rational s(-5, 9);
	algebra::Rational o(2, 3);
	s /= o;

	ASSERT_THAT(s.get_numerator() == -15);
	ASSERT_THAT(s.get_denumerator() == 18);

END_TEST

BEGIN_TEST(operator_divide_on_self_negative_by_negative_rational)

	algebra::Rational s(-5, 9);
	algebra::Rational o(-6, 7);
	s /= o;

	ASSERT_THAT(s.get_numerator() == 35);
	ASSERT_THAT(s.get_denumerator() == 54);

END_TEST

BEGIN_TEST(operator_divide_on_self_positive_by_negative_rational)

	algebra::Rational s(5, 9);
	algebra::Rational o(-6, 7);
	s /= o;

	ASSERT_THAT(s.get_numerator() == -35);
	ASSERT_THAT(s.get_denumerator() == 54);

END_TEST

BEGIN_TEST(operator_divide_on_self_negative_by_1)

	algebra::Rational s(-5, 9);
	algebra::Rational o(1, 1);
	s /= o;

	ASSERT_THAT(s.get_numerator() == -5);
	ASSERT_THAT(s.get_denumerator() == 9);

END_TEST

BEGIN_TEST(operator_divide_on_self_positive_by_negative_int)

	algebra::Rational s(5, 9);
	int n = -6;
	s /= n;

	ASSERT_THAT(s.get_numerator() == -5);
	ASSERT_THAT(s.get_denumerator() == 54);

END_TEST

BEGIN_TEST(operator_divide_on_self_positive_by_positive_int)

	algebra::Rational s(-5, 9);
	int n = -6;
	s /= n;

	ASSERT_THAT(s.get_numerator() == 5);
	ASSERT_THAT(s.get_denumerator() == 54);


END_TEST

//test with negative self and negative int

//global operator *

BEGIN_TEST(global_operator_mult_by_zero)

	algebra::Rational s(5, 9);
	algebra::Rational o(0);
	algebra::Rational r = s * o;

	ASSERT_THAT(r.get_numerator() == 0);
	ASSERT_THAT(s.get_numerator() > r.get_numerator());
	ASSERT_THAT(r.get_numerator() == o.get_numerator());

END_TEST

BEGIN_TEST(global_operator_mult_by_positive_rational)

	algebra::Rational s(5, 9);
	algebra::Rational o(3, 5);
	algebra::Rational r = s * o;

	ASSERT_THAT(r.get_numerator() == 15);
	ASSERT_THAT(r.get_denumerator() == 45);

END_TEST

BEGIN_TEST(global_operator_mult_by_negative_rational)

	algebra::Rational s(5, 9);
	algebra::Rational o(-3, 5);
	algebra::Rational r = s * o;

	ASSERT_THAT(r.get_numerator() == -15);
	ASSERT_THAT(r.get_denumerator() == 45);


END_TEST

BEGIN_TEST(global_operator_mult_by_positive_int)

	algebra::Rational s(5, 9);
	int n = 4;
	algebra::Rational r = s * n;

	ASSERT_THAT(r.get_numerator() == 20);
	ASSERT_THAT(r.get_denumerator() == 9);

END_TEST

BEGIN_TEST(global_operator_mult_by_negative_int)

	algebra::Rational s(5, 9);
	int n = -4;
	algebra::Rational r = s * n;

	ASSERT_THAT(r.get_numerator() == -20);
	ASSERT_THAT(r.get_denumerator() == 9);

END_TEST

//add tests with big numbers

//global operator +

BEGIN_TEST(global_operator_add_with_rational_zero)

	algebra::Rational s(5, 9);
	algebra::Rational o(0);
	algebra::Rational r = s + o;
	
	ASSERT_THAT(r.get_numerator() == 5);
	ASSERT_THAT(r.get_denumerator() == 9);

END_TEST

BEGIN_TEST(global_operator_add_with_one)

	algebra::Rational s(5, 9);
	algebra::Rational o(1,1);
	algebra::Rational r = s + o;

	ASSERT_THAT(r.get_numerator() == 14);
	ASSERT_THAT(r.get_denumerator() == 9);

END_TEST

BEGIN_TEST(global_operator_add_with_negative_rational)

	algebra::Rational s(5, 9);
	algebra::Rational o(-2, 3);
	algebra::Rational r = s + o;

	ASSERT_THAT(r.get_numerator() == -1);
	ASSERT_THAT(r.get_denumerator() == 9);

END_TEST

BEGIN_TEST(global_operator_add_with_two_positive_rationals)

	algebra::Rational s(5, 9);
	algebra::Rational o(2, 3);
	algebra::Rational r = s + o;

	ASSERT_THAT(r.get_numerator() == 11);
	ASSERT_THAT(r.get_denumerator() == 9);

END_TEST

//add here  test with two negative rationals

BEGIN_TEST(global_operator_add_with_positive_int)

	algebra::Rational s(5, 9);
	int n = 2;

	algebra::Rational r = s + n;

	ASSERT_THAT(r.get_numerator() == 23);
	ASSERT_THAT(r.get_denumerator() == 9);

END_TEST

BEGIN_TEST(global_operator_add_with_negative_int)

	algebra::Rational s(5, 9);
	int n = -2;

	algebra::Rational r = s + n;

	ASSERT_THAT(r.get_numerator() == -13);
	ASSERT_THAT(r.get_denumerator() == 9);

END_TEST

//add tests with big numbers


//global operator function -

BEGIN_TEST(global_operator_subtruct_with_one)

	algebra::Rational s(5, 9);
	algebra::Rational o(1, 1);
	algebra::Rational r = s - o;

	ASSERT_THAT(r.get_numerator() == -4);
	ASSERT_THAT(r.get_denumerator() == 9);


END_TEST

BEGIN_TEST(global_operator_subtruct_with_positive_rational)

	algebra::Rational s(5, 9);
	algebra::Rational o(2, 3);
	algebra::Rational r = s - o;

	ASSERT_THAT(r.get_numerator() == -1);
	ASSERT_THAT(r.get_denumerator() == 9);


END_TEST

BEGIN_TEST(global_operator_subtruct_with_negative_rational)

	algebra::Rational s(5, 9);
	algebra::Rational o(-2, 3);
	algebra::Rational r = s - o;

	ASSERT_THAT(r.get_numerator() == 11);
	ASSERT_THAT(r.get_denumerator() == 9);


END_TEST

BEGIN_TEST(global_operator_subtruct_with_equal_rational)

	algebra::Rational s(5, 9);
	algebra::Rational o(5, 9);
	algebra::Rational r = s - o;

	ASSERT_THAT(r.get_numerator() == 0);
	ASSERT_THAT(r.get_denumerator() == 9);

END_TEST

//add tests with big numbers

//global function operator /

BEGIN_TEST(global_operator_divide_by_one)

	algebra::Rational s(5, 9);
	algebra::Rational o(1, 1);
	algebra::Rational r = s / o;

	ASSERT_THAT(r.get_numerator() == 5);
	ASSERT_THAT(r.get_denumerator() == 9);

END_TEST

BEGIN_TEST(global_operator_divide_positive_by_positive)

	algebra::Rational s(5, 9);
	algebra::Rational o(4, 5);
	algebra::Rational r = s / o;

	ASSERT_THAT(r.get_numerator() == 25);
	ASSERT_THAT(r.get_denumerator() == 36);

END_TEST

BEGIN_TEST(global_operator_divide_negative_by_positive)

	algebra::Rational s(-5, 9);
	algebra::Rational o(4, 5);
	algebra::Rational r = s / o;

	ASSERT_THAT(r.get_numerator() == -25);
	ASSERT_THAT(r.get_denumerator() == 36);

END_TEST

BEGIN_TEST(global_operator_divide_positive_by_negative)

	algebra::Rational s(5, 9);
	algebra::Rational o(-4, 5);
	algebra::Rational r = s / o;

	ASSERT_THAT(r.get_numerator() == -25);
	ASSERT_THAT(r.get_denumerator() == 36);

END_TEST

BEGIN_TEST(global_operator_divide_negative_by_negative)

	algebra::Rational s(-5, 9);
	algebra::Rational o(-4, 5);
	algebra::Rational r = s / o;

	ASSERT_THAT(r.get_numerator() == 25);
	ASSERT_THAT(r.get_denumerator() == 36);

END_TEST

BEGIN_TEST(global_operator_divide_negative_by_negative_int)

	algebra::Rational s(-5, 9);
	int n = -4;
	algebra::Rational r = s / n;

	ASSERT_THAT(r.get_numerator() == 5);
	ASSERT_THAT(r.get_denumerator() == 36);

END_TEST

BEGIN_TEST(global_operator_divide_negative_by_positive_int)

	algebra::Rational s(-5, 9);
	int n = 4;
	algebra::Rational r = s / n;

	ASSERT_THAT(r.get_numerator() == -5);
	ASSERT_THAT(r.get_denumerator() == 36);

END_TEST

BEGIN_TEST(global_operator_divide_positive_by_negative_int)

	algebra::Rational s(5, 6);
	int n = -6;
	algebra::Rational r = s / n;

	ASSERT_THAT(r.get_numerator() == -5);
	ASSERT_THAT(r.get_denumerator() == 36);

END_TEST

BEGIN_TEST(global_operator_divide_positive_by_positive_int)

	algebra::Rational s(20, 30);
	int n = 2;
	algebra::Rational r = s / n;

	ASSERT_THAT(r.get_numerator() == 20);
	ASSERT_THAT(r.get_denumerator() == 60);

END_TEST

// global function operator <

BEGIN_TEST(global_operator_smaller_than_when_true_both_pos)

	algebra::Rational s(5, 9);
	algebra::Rational o(1, 1);
	bool r = s < o;

	ASSERT_THAT(r == 1);

END_TEST

BEGIN_TEST(global_operator_smaller_than_when_false)

	algebra::Rational s(5, 9);
	algebra::Rational o(1, 10);
	bool r = s < o;

	ASSERT_THAT(r == 0);

END_TEST


BEGIN_TEST(global_operator_smaller_than_when_first_positive_sec_negative)

	algebra::Rational s(5, 9);
	algebra::Rational o(-1, 10);
	bool r = s < o;

	ASSERT_THAT(r == 0);

END_TEST

BEGIN_TEST(global_operator_smaller_than_when_first_negative_sec_positive)

	algebra::Rational s(-5, 9);
	algebra::Rational o(1, 5);
	bool r = s < o;

	ASSERT_THAT(r == 1);

END_TEST

BEGIN_TEST(global_operator_smaller_than_when_first_negative_sec_negative)

	algebra::Rational s(-2, 3);
	algebra::Rational o(-4, 10);
	bool r = s < o;

	ASSERT_THAT(r == 1);

END_TEST

//test also when false
//test with zero

//global function operator >

BEGIN_TEST(global_operator_bigger_than_when_false_both_pos)

	algebra::Rational s(5, 9);
	algebra::Rational o(1, 1);
	bool r = s > o;

	ASSERT_THAT(r == 0);

END_TEST

BEGIN_TEST(global_operator_bigger_than_when_true)

	algebra::Rational s(5, 9);
	algebra::Rational o(1, 10);
	bool r = s > o;

	ASSERT_THAT(r == 1);

END_TEST


BEGIN_TEST(global_operator_bigger_than_when_first_positive_sec_negative)

	algebra::Rational s(5, 9);
	algebra::Rational o(-1, 10);
	bool r = s > o;

	ASSERT_THAT(r == 1);

END_TEST

BEGIN_TEST(global_operator_bigger_than_when_first_negative_sec_positive)

	algebra::Rational s(-5, 9);
	algebra::Rational o(1, 5);
	bool r = s > o;

	ASSERT_THAT(r == 0);

END_TEST

BEGIN_TEST(global_operator_bigger_than_when_first_negative_sec_negative)

	algebra::Rational s(-2, 3);
	algebra::Rational o(-1, 10);
	bool r = s > o;

	ASSERT_THAT(r == 0);

END_TEST

//global function operator ==

BEGIN_TEST(global_operator_isEqual_when_false_both_pos)

	algebra::Rational s(5, 9);
	algebra::Rational o(1, 1);
	bool r = s == o;

	ASSERT_THAT(r == 0);

END_TEST


BEGIN_TEST(global_operator_isEqual_when_true_both_pos)

	algebra::Rational s(5, 9);
	algebra::Rational o(5, 9);
	bool r = s == o;

	ASSERT_THAT(r == 1);

END_TEST

BEGIN_TEST(global_operator_isEqual_when_true_both_pos2)

	algebra::Rational s(5, 9);
	algebra::Rational o(10, 18);
	bool r = s == o;

	ASSERT_THAT(r == 1);

END_TEST

BEGIN_TEST(global_operator_isEqual_when_false_both_neg)

	algebra::Rational s(-5, 9);
	algebra::Rational o(-1, 1);
	bool r = s == o;

	ASSERT_THAT(r == 0);

END_TEST

BEGIN_TEST(global_operator_isEqual_when_true_both_neg)

	algebra::Rational s(-5, 9);
	algebra::Rational o(-5, 9);
	bool r = s == o;

	ASSERT_THAT(r == 1);

END_TEST

BEGIN_TEST(global_operator_isEqual_when_true_with_int)

	algebra::Rational s(-6, 3);
	int n = -2;
	bool r = s == n;

	ASSERT_THAT(r == 1);

END_TEST

BEGIN_TEST(global_operator_isEqual_when_false_with_int)

	algebra::Rational s(-5, 3);
	int n = -2;
	bool r = s == n;

	ASSERT_THAT(r == 0);

END_TEST

//test with positive int as well

//global function operator !=

BEGIN_TEST(global_operator_notEqual_when_true_both_pos)

	algebra::Rational s(5, 9);
	algebra::Rational o(1, 1);
	bool r = s != o;

	ASSERT_THAT(r == 1);

END_TEST

BEGIN_TEST(global_operator_notEqual_when_false_both_pos)

	algebra::Rational s(5, 9);
	algebra::Rational o(5, 9);
	bool r = s != o;

	ASSERT_THAT(r == 0);

END_TEST

BEGIN_TEST(global_operator_notEqual_when_false_both_pos2)

	algebra::Rational s(5, 9);
	algebra::Rational o(10, 18);
	bool r = s != o;

	ASSERT_THAT(r == 0);

END_TEST

BEGIN_TEST(global_operator_notEqual_when_true_both_neg)

	algebra::Rational s(-5, 9);
	algebra::Rational o(-1, 1);
	bool r = s != o;

	ASSERT_THAT(r == 1);

END_TEST

BEGIN_TEST(global_operator_notEqual_when_false_both_neg)

	algebra::Rational s(-5, 9);
	algebra::Rational o(-5, 9);
	bool r = s != o;

	ASSERT_THAT(r == 0);

END_TEST

BEGIN_TEST(global_operator_notEqual_when_false_with_int)

	algebra::Rational s(-6, 3);
	int n = -2;
	bool r = s != n;

	ASSERT_THAT(r == 0);

END_TEST

BEGIN_TEST(global_operator_notEqual_when_true_with_int)

	algebra::Rational s(-5, 3);
	int n = -2;
	bool r = s != n;

	ASSERT_THAT(r == 1);

END_TEST

//global function operator !

BEGIN_TEST(global_operator_isZero_on_rational_true)

	algebra::Rational s(0, 9);
	bool r = !s;

	ASSERT_THAT(r == 1);

END_TEST

BEGIN_TEST(global_operator_isZero_on_positive_rational_false)

	algebra::Rational s(5, 9);
	bool r = !s;

	ASSERT_THAT(r == 0);

END_TEST

BEGIN_TEST(global_operator_isZero_on_negative_rational_false)

	algebra::Rational s(-5, 9);
	bool r = !s;

	ASSERT_THAT(r == 0);

END_TEST

BEGIN_TEST(global_operator_isZero_on_int_true)

	int n = 0;
	bool r = !n;

	ASSERT_THAT(r == 1);

END_TEST

BEGIN_TEST(global_operator_isZero_on_positive_int_false)

	int n = 3;
	bool r = !n;

	ASSERT_THAT(r == 0);

END_TEST

BEGIN_TEST(global_operator_isZero_on_negative_int_false)

	int n = -3;
	bool r = !n;

	ASSERT_THAT(r == 0);

END_TEST


//global function add two rationals
BEGIN_TEST(global_add_rationals_equals)

	algebra::Rational s(1, 3);
	algebra::Rational o(1, 3);
	algebra::Rational r = add_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == 2);
	ASSERT_THAT(r.get_denumerator() == 3);	

END_TEST

BEGIN_TEST(global_add_rationals_when_self_denum_contains_the_other_denum)

	algebra::Rational s(1, 6);
	algebra::Rational o(1, 2);
	algebra::Rational r = add_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == 4);
	ASSERT_THAT(r.get_denumerator() == 6);

END_TEST

BEGIN_TEST(global_add_rationals_when_other_denum_contains_the_self_denum)

	algebra::Rational s(1, 3);
	algebra::Rational o(1, 6);
	algebra::Rational r = add_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == 3);
	ASSERT_THAT(r.get_denumerator() == 6);

END_TEST

BEGIN_TEST(global_add_rationals_when_passing_positive_int)

	algebra::Rational s(1, 3);
	int n = 6;
	algebra::Rational r = add_two_rationals(s, n);

	ASSERT_THAT(r.get_numerator() == 19);
	ASSERT_THAT(r.get_denumerator() == 3);

END_TEST

BEGIN_TEST(global_add_rationals_when_passing_negative_int)

	algebra::Rational s(1, 3);
	int n = -6;
	algebra::Rational r = add_two_rationals(s, n);

	ASSERT_THAT(r.get_numerator() == -17);
	ASSERT_THAT(r.get_denumerator() == 3);

END_TEST

BEGIN_TEST(global_add_rationals_both_negative)

	algebra::Rational s(-4, 12);
	algebra::Rational o(-2, 6);
	algebra::Rational r = add_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == -8);
	ASSERT_THAT(r.get_denumerator() == 12);	

END_TEST

BEGIN_TEST(global_add_rationals_one_is_negative)

	algebra::Rational s(-4, 12);
	algebra::Rational o(2, 6);
	algebra::Rational r = add_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == 0);
	ASSERT_THAT(r.get_denumerator() == 12);	

END_TEST

BEGIN_TEST(global_add_rationals_one_is_negative2)

	algebra::Rational s(4, 12);
	algebra::Rational o(-12, 6);
	algebra::Rational r = add_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == -20);
	ASSERT_THAT(r.get_denumerator() == 12);	

END_TEST

BEGIN_TEST(global_add_rationals_big_positive_numbers)

	algebra::Rational s(5620, 12360);
	algebra::Rational o(231, 400);
	algebra::Rational r = add_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == 5103160);
	ASSERT_THAT(r.get_denumerator() == 4944000);	

END_TEST

BEGIN_TEST(global_add_rationals_big_negative_numbers)

	algebra::Rational s(-5620, 12360);
	algebra::Rational o(-231, 400);
	algebra::Rational r = add_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == -5103160);
	ASSERT_THAT(r.get_denumerator() == 4944000);	

END_TEST

//global function subtruct two rationals

BEGIN_TEST(global_substruct_rationals_equals)	
	
	algebra::Rational s(1, 3);
	algebra::Rational o(1, 3);
	algebra::Rational r = substruct_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == 0);
	ASSERT_THAT(r.get_denumerator() == 3);
	

END_TEST

BEGIN_TEST(global_substruct_rationals_when_self_denum_contains_the_other_denum)

	algebra::Rational s(5, 9);
	algebra::Rational o(1, 3);
	algebra::Rational r = substruct_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == 2);
	ASSERT_THAT(r.get_denumerator() == 9);		

END_TEST

BEGIN_TEST(global_substruct_rationals_when_other_denum_contains_the_self_denum)

	algebra::Rational s(4, 6);
	algebra::Rational o(5, 18);
	algebra::Rational r = substruct_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == 7);
	ASSERT_THAT(r.get_denumerator() == 18);	

END_TEST

BEGIN_TEST(global_subtruct_when_self_smaller_then_other)

	algebra::Rational s(1, 6);
	algebra::Rational o(5, 6);
	algebra::Rational r = substruct_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == -4);
	ASSERT_THAT(r.get_denumerator() == 6);

END_TEST

BEGIN_TEST(global_subtruct_when_passing_positive_int)

	algebra::Rational s(1, 6);
	int n = 5;
	algebra::Rational r = substruct_two_rationals(s, n);

	ASSERT_THAT(r.get_numerator() == -29);
	ASSERT_THAT(r.get_denumerator() == 6);

END_TEST

BEGIN_TEST(global_subtruct_when_passing_negative_int)

	algebra::Rational s(1, 6);
	int n = -5;
	algebra::Rational r = substruct_two_rationals(s, n);

	ASSERT_THAT(r.get_numerator() == 31);
	ASSERT_THAT(r.get_denumerator() == 6);

END_TEST

BEGIN_TEST(global_subtruct_rationals_both_negative)

	algebra::Rational s(-4, 12);
	algebra::Rational o(-2, 6);
	algebra::Rational r = substruct_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == 0);
	ASSERT_THAT(r.get_denumerator() == 12);	

END_TEST

BEGIN_TEST(global_subtruct_rationals_one_is_negative)

	algebra::Rational s(-4, 12);
	algebra::Rational o(2, 6);
	algebra::Rational r = substruct_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == -8);
	ASSERT_THAT(r.get_denumerator() == 12);	

END_TEST

BEGIN_TEST(global_subtruct_rationals_one_is_negative2)

	algebra::Rational s(4, 12);
	algebra::Rational o(-12, 6);
	algebra::Rational r = substruct_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == 28);
	ASSERT_THAT(r.get_denumerator() == 12);	

END_TEST

BEGIN_TEST(global_subtruct_rationals_big_positive_numbers)

	algebra::Rational s(5620, 12360);
	algebra::Rational o(231, 400);
	algebra::Rational r = substruct_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == -607160);
	ASSERT_THAT(r.get_denumerator() == 4944000);	

END_TEST

BEGIN_TEST(global_subtruct_rationals_big_negative_numbers)

	algebra::Rational s(-5620, 12360);
	algebra::Rational o(-231, 400);
	algebra::Rational r = substruct_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == 607160);
	ASSERT_THAT(r.get_denumerator() == 4944000);	

END_TEST

//global function multiply two rationals

BEGIN_TEST(global_multiply_when_one_rational_is_zero)

	algebra::Rational s(0, 6);
	algebra::Rational o(5, 7);
	algebra::Rational r = multiply_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == 0);
	ASSERT_THAT(r.get_denumerator() == 42);

END_TEST

BEGIN_TEST(global_multiply_when_other_rational_is_zero)

	algebra::Rational s(12, 3);
	algebra::Rational o(0, 20);
	algebra::Rational r = multiply_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == 0);
	ASSERT_THAT(r.get_denumerator() == 60);


END_TEST

BEGIN_TEST(global_multiply_when_both_are_zero)

	algebra::Rational s(0, 12);
	algebra::Rational o(0, 20);
	algebra::Rational r = multiply_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == 0);
	ASSERT_THAT(r.get_denumerator() == 240);

END_TEST

BEGIN_TEST(global_multiply_when_one_rational_is_one)

	algebra::Rational s(1, 12);
	algebra::Rational o(10, 20);
	algebra::Rational r = multiply_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == 10);
	ASSERT_THAT(r.get_denumerator() == 240);


END_TEST

BEGIN_TEST(global_multiply_when_other_rational_is_one)

	algebra::Rational s(14, 12);
	algebra::Rational o(1, 20);
	algebra::Rational r = multiply_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == 14);
	ASSERT_THAT(r.get_denumerator() == 240);


END_TEST

BEGIN_TEST(global_multiply_when_both_numerators_are_one)

	algebra::Rational s(1, 12);
	algebra::Rational o(1, 20);
	algebra::Rational r = multiply_two_rationals(s, o);


	ASSERT_THAT(r.get_numerator() == 1);
	ASSERT_THAT(r.get_denumerator() == 240);


END_TEST

BEGIN_TEST(global_multiply_when_both_positive)

	algebra::Rational s(14, 15);
	algebra::Rational o(15, 20);
	algebra::Rational r = multiply_two_rationals(s, o);


	ASSERT_THAT(r.get_numerator() == 210);
	ASSERT_THAT(r.get_denumerator() == 300);

END_TEST

BEGIN_TEST(global_multiply_when_both_positive2)

	algebra::Rational s(-14, -15);
	algebra::Rational o(-15, -20);
	algebra::Rational r = multiply_two_rationals(s, o);


	ASSERT_THAT(r.get_numerator() == 210);
	ASSERT_THAT(r.get_denumerator() == 300);

END_TEST


BEGIN_TEST(global_multiply_when_one_is_negative)

	algebra::Rational s(-3, 12);
	algebra::Rational o(15, 20);
	algebra::Rational r = multiply_two_rationals(s, o);


	ASSERT_THAT(r.get_numerator() == -45);
	ASSERT_THAT(r.get_denumerator() == 240);

END_TEST

BEGIN_TEST(global_multiply_when_other_is_negative)

	algebra::Rational s(3, 12);
	algebra::Rational o(-12, 20);
	algebra::Rational r = multiply_two_rationals(s, o);


	ASSERT_THAT(r.get_numerator() == -36);
	ASSERT_THAT(r.get_denumerator() == 240);

END_TEST

BEGIN_TEST(global_multiply_when_both_are_negative)

	algebra::Rational s(-3, 10);
	algebra::Rational o(-15, 20);
	algebra::Rational r = multiply_two_rationals(s, o);


	ASSERT_THAT(r.get_numerator() == 45);
	ASSERT_THAT(r.get_denumerator() == 200);
END_TEST

BEGIN_TEST(global_multiply_with_big_rationals)

	algebra::Rational s(550, 2040);
	algebra::Rational o(1560, 1234);
	algebra::Rational r = multiply_two_rationals(s, o);


	ASSERT_THAT(r.get_numerator() == 858000);
	ASSERT_THAT(r.get_denumerator() == 2517360);

END_TEST

BEGIN_TEST(global_multiply_when_passing_a_positive_int)

	algebra::Rational s(12, 3);
	int n = 20;
	algebra::Rational r = multiply_two_rationals(s, n);

	ASSERT_THAT(r.get_numerator() == 240);
	ASSERT_THAT(r.get_denumerator() == 3);

END_TEST

BEGIN_TEST(global_multiply_when_passing_a_positive_int2)

	algebra::Rational s(-12, 3);
	int n = 20;
	algebra::Rational r = multiply_two_rationals(s, n);

	ASSERT_THAT(r.get_numerator() == -240);
	ASSERT_THAT(r.get_denumerator() == 3);

END_TEST

BEGIN_TEST(global_multiply_when_passing_a_negative_int)

	algebra::Rational s(12, 3);
	int n = -20;
	algebra::Rational r = multiply_two_rationals(s, n);

	ASSERT_THAT(r.get_numerator() == -240);
	ASSERT_THAT(r.get_denumerator() == 3);

END_TEST

BEGIN_TEST(global_multiply_when_passing_a_negative_int2)

	algebra::Rational s(-12, 3);
	int n = -20;
	algebra::Rational r = multiply_two_rationals(s, n);

	ASSERT_THAT(r.get_numerator() == 240);
	ASSERT_THAT(r.get_denumerator() == 3);

END_TEST

//global function divide two rationals

BEGIN_TEST(global_divide_when_self_rational_is_zero)

	algebra::Rational s(0, 20);
	algebra::Rational o(15, 34);
	algebra::Rational r = divide_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == 0);
	ASSERT_THAT(r.get_denumerator() == 300);

END_TEST

BEGIN_TEST(global_divide_when_self_rational_is_one)

	algebra::Rational s(1, 13);
	algebra::Rational o(2, 4);
	algebra::Rational r = divide_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == 4);
	ASSERT_THAT(r.get_denumerator() == 26);

END_TEST

BEGIN_TEST(global_divide_when_other_rational_is_one)

	algebra::Rational s(5, 13);
	algebra::Rational o(1, 10);
	algebra::Rational r = divide_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == 50);
	ASSERT_THAT(r.get_denumerator() == 13);

END_TEST

BEGIN_TEST(global_divide_when_both_are_one)

	algebra::Rational s(1, 13);
	algebra::Rational o(1, 10);
	algebra::Rational r = divide_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == 10);
	ASSERT_THAT(r.get_denumerator() == 13);

END_TEST

BEGIN_TEST(global_divide_when_both_are_positive)

	algebra::Rational s(20, 35);
	algebra::Rational o(3, 10);
	algebra::Rational r = divide_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == 200);
	ASSERT_THAT(r.get_denumerator() == 105);

END_TEST

BEGIN_TEST(global_divide_when_both_are_negative)

	algebra::Rational s(-20, 35);
	algebra::Rational o(-3, 10);
	algebra::Rational r = divide_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == 200);
	ASSERT_THAT(r.get_denumerator() == 105);

END_TEST

BEGIN_TEST(global_divide_when_self_rational_numerator_is_negative)

	algebra::Rational s(-5, 13);
	algebra::Rational o(8, 10);
	algebra::Rational r = divide_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == -50);
	ASSERT_THAT(r.get_denumerator() == 104);

END_TEST

BEGIN_TEST(global_divide_when_other_rational_numerator_is_negative)

	algebra::Rational s(5, 13);
	algebra::Rational o(-28, 100);
	algebra::Rational r = divide_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == -500);
	ASSERT_THAT(r.get_denumerator() == 364);

END_TEST

BEGIN_TEST(global_divide_rationals_with_big_numbers)

	algebra::Rational s(5630, 20147);
	algebra::Rational o(360, 5400);
	algebra::Rational r = divide_two_rationals(s, o);

	ASSERT_THAT(r.get_numerator() == 30402000);
	ASSERT_THAT(r.get_denumerator() == 7252920);

END_TEST

BEGIN_TEST(global_divide_when_passing_a_positive_int)

	algebra::Rational s(5, 10);
	int n = 5;
	algebra::Rational r = divide_two_rationals(s, n);

	ASSERT_THAT(r.get_numerator() == 5);
	ASSERT_THAT(r.get_denumerator() == 50);

END_TEST

BEGIN_TEST(global_divide_when_passing_a_positive_int2)

	algebra::Rational s(-5, 10);
	int n = 5;
	algebra::Rational r = divide_two_rationals(s, n);

	ASSERT_THAT(r.get_numerator() == -5);
	ASSERT_THAT(r.get_denumerator() == 50);

END_TEST

BEGIN_TEST(global_divide_when_passing_a_negative_int)

	algebra::Rational s(5, 10);
	int n = -10;
	algebra::Rational r = divide_two_rationals(s, n);

	ASSERT_THAT(r.get_numerator() == -5);
	ASSERT_THAT(r.get_denumerator() == 100);

END_TEST

BEGIN_TEST(global_divide_when_passing_a_negative_int2)

	algebra::Rational s(-5, 10);
	int n = -10;
	algebra::Rational r = divide_two_rationals(s, n);

	ASSERT_THAT(r.get_numerator() == 5);
	ASSERT_THAT(r.get_denumerator() == 100);

END_TEST


BEGIN_SUITE(Its what you learn after you know it all that counts)

	TEST(add_rationals_equals)
	TEST(add_rationals_when_self_denum_contains_the_other_denum)
	TEST(add_rationals_when_other_denum_contains_the_self_denum)
	TEST(add_rationals_when_passing_positive_int)
	TEST(add_rationals_when_passing_negative_int)

	TEST(substruct_rationals_equals)
	TEST(substruct_rationals_when_self_denum_contains_the_other_denum)
	TEST(substruct_rationals_when_other_denum_contains_the_self_denum)
	TEST(substruct_when_self_smaller_then_other)
	TEST(substruct_when_passing_positive_int)
	TEST(substruct_when_passing_negative_int)

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
	TEST(multiply_when_passing_an_int)

	TEST(divide_when_self_rational_is_zero)
	TEST(divide_when_self_rational_is_one)
	TEST(divide_when_other_rational_is_one)
	TEST(divide_when_both_are_one)
	TEST(divide_when_self_rational_numerator_is_negative)
	TEST(divide_when_other_rational_numerator_is_negative)
	TEST(divide_when_passing_a_positive_int)
	TEST(divide_when_passing_a_negative_int)

	TEST(reduce_when_self_numerator_is_one)
	TEST(reduce_when_self_denumerator_is_one)
	TEST(reduce_when_self_numerator_is_zero)
	TEST(reduce_when_self_reducable_and_negative)
	TEST(reduce_when_self_reducable_and_positive)
	TEST(reduce_when_self_unreducable_and_negative)
	TEST(reduce_when_self_unreducable_and_positive)
	TEST(reduce_when_self_reducable_and_negative_big_rational)
	TEST(reduce_when_self_reducable_and_positive_big_rational)

	TEST(operator_mult_on_self_by_zero)
	TEST(operator_mult_on_self_by_positive_rational)
	TEST(operator_mult_on_self_by_negative_rational)
	TEST(operator_mult_on_self_by_positive_int)
	TEST(operator_mult_on_self_by_negative_int)

	TEST(operator_add_on_self_with_rational_zero)
	TEST(operator_add_on_self_with_negative_rational)
	TEST(operator_add_on_self_with_positive_rational)
	TEST(operator_add_on_self_with_positive_int)
	TEST(operator_add_on_self_with_negative_int)

	TEST(operator_subtruct_on_self_with_one)
	TEST(operator_subtruct_on_self_with_positive_rational)
	TEST(operator_subtruct_on_self_with_negative_rational)
	TEST(operator_subtruct_on_self_with_equal_rational)

	TEST(operator_divide_on_self_positive_by_positive_rational)
	TEST(operator_divide_on_self_negative_by_positive_rational)
	TEST(operator_divide_on_self_negative_by_negative_rational)
	TEST(operator_divide_on_self_positive_by_negative_rational)
	TEST(operator_divide_on_self_negative_by_1)
	TEST(operator_divide_on_self_positive_by_negative_int)
	TEST(operator_divide_on_self_positive_by_positive_int)

	TEST(global_operator_mult_by_zero)
	TEST(global_operator_mult_by_positive_rational)
	TEST(global_operator_mult_by_negative_rational)
	TEST(global_operator_mult_by_positive_int)
	TEST(global_operator_mult_by_negative_int)

	TEST(global_operator_add_with_rational_zero)
	TEST(global_operator_add_with_one)
	TEST(global_operator_add_with_negative_rational)
	TEST(global_operator_add_with_two_positive_rationals)
	TEST(global_operator_add_with_positive_int)
	TEST(global_operator_add_with_negative_int)

	TEST(global_operator_subtruct_with_one)
	TEST(global_operator_subtruct_with_positive_rational)
	TEST(global_operator_subtruct_with_negative_rational)
	TEST(global_operator_subtruct_with_equal_rational)

	TEST(global_operator_divide_by_one)
	TEST(global_operator_divide_positive_by_positive)
	TEST(global_operator_divide_negative_by_positive)
	TEST(global_operator_divide_positive_by_negative)
	TEST(global_operator_divide_negative_by_negative)
	TEST(global_operator_divide_negative_by_negative_int)
	TEST(global_operator_divide_negative_by_positive_int)
	TEST(global_operator_divide_positive_by_negative_int)
	TEST(global_operator_divide_positive_by_positive_int)

	TEST(global_operator_smaller_than_when_true_both_pos)
	TEST(global_operator_smaller_than_when_false)
	TEST(global_operator_smaller_than_when_first_positive_sec_negative)
	TEST(global_operator_smaller_than_when_first_negative_sec_positive)
	TEST(global_operator_smaller_than_when_first_negative_sec_negative)

	TEST(global_operator_bigger_than_when_false_both_pos)
	TEST(global_operator_bigger_than_when_true)
	TEST(global_operator_bigger_than_when_first_positive_sec_negative)
	TEST(global_operator_bigger_than_when_first_negative_sec_positive)
	TEST(global_operator_bigger_than_when_first_negative_sec_negative)

	TEST(global_operator_isEqual_when_false_both_pos)
	TEST(global_operator_isEqual_when_true_both_pos)
	TEST(global_operator_isEqual_when_true_both_pos2)
	TEST(global_operator_isEqual_when_false_both_neg)
	TEST(global_operator_isEqual_when_true_both_neg)
	TEST(global_operator_isEqual_when_true_with_int)
	TEST(global_operator_isEqual_when_false_with_int)

	TEST(global_operator_notEqual_when_true_both_pos)
	TEST(global_operator_notEqual_when_false_both_pos)
	TEST(global_operator_notEqual_when_false_both_pos2)
	TEST(global_operator_notEqual_when_true_both_neg)
	TEST(global_operator_notEqual_when_false_both_neg)
	TEST(global_operator_notEqual_when_false_with_int)
	TEST(global_operator_notEqual_when_true_with_int)

	TEST(global_operator_isZero_on_rational_true)
	TEST(global_operator_isZero_on_positive_rational_false)
	TEST(global_operator_isZero_on_negative_rational_false)
	TEST(global_operator_isZero_on_int_true)
	TEST(global_operator_isZero_on_positive_int_false)
	TEST(global_operator_isZero_on_negative_int_false)

	TEST(global_add_rationals_equals)
	TEST(global_add_rationals_when_self_denum_contains_the_other_denum)
	TEST(global_add_rationals_when_other_denum_contains_the_self_denum)
	TEST(global_add_rationals_when_passing_positive_int)
	TEST(global_add_rationals_when_passing_negative_int)
	TEST(global_add_rationals_both_negative)
	TEST(global_add_rationals_one_is_negative)
	TEST(global_add_rationals_one_is_negative2)
	TEST(global_add_rationals_big_positive_numbers)
	TEST(global_add_rationals_big_negative_numbers)

	TEST(global_substruct_rationals_equals)
	TEST(global_substruct_rationals_when_self_denum_contains_the_other_denum)
	TEST(global_substruct_rationals_when_other_denum_contains_the_self_denum)
	TEST(global_subtruct_when_self_smaller_then_other)
	TEST(global_subtruct_when_passing_positive_int)
	TEST(global_subtruct_when_passing_negative_int)
	TEST(global_subtruct_rationals_both_negative)
	TEST(global_subtruct_rationals_one_is_negative)
	TEST(global_subtruct_rationals_one_is_negative2)
	TEST(global_subtruct_rationals_big_positive_numbers)
	TEST(global_subtruct_rationals_big_negative_numbers)

	TEST(global_multiply_when_one_rational_is_zero)
	TEST(global_multiply_when_other_rational_is_zero)
	TEST(global_multiply_when_both_are_zero)
	TEST(global_multiply_when_one_rational_is_one)
	TEST(global_multiply_when_other_rational_is_one)
	TEST(global_multiply_when_both_numerators_are_one)
	TEST(global_multiply_when_both_positive)
	TEST(global_multiply_when_both_positive2)
	TEST(global_multiply_when_one_is_negative)
	TEST(global_multiply_when_other_is_negative)
	TEST(global_multiply_when_both_are_negative)
	TEST(global_multiply_with_big_rationals)
	TEST(global_multiply_when_passing_a_positive_int)
	TEST(global_multiply_when_passing_a_positive_int2)
	TEST(global_multiply_when_passing_a_negative_int)
	TEST(global_multiply_when_passing_a_negative_int2)

	TEST(global_divide_when_self_rational_is_zero)
	TEST(global_divide_when_self_rational_is_one)
	TEST(global_divide_when_other_rational_is_one)
	TEST(global_divide_when_both_are_one)
	TEST(global_divide_when_both_are_positive)
	TEST(global_divide_when_both_are_negative)
	TEST(global_divide_when_self_rational_numerator_is_negative)
	TEST(global_divide_when_other_rational_numerator_is_negative)
	TEST(global_divide_rationals_with_big_numbers)
	TEST(global_divide_when_passing_a_positive_int)
	TEST(global_divide_when_passing_a_positive_int2)
	TEST(global_divide_when_passing_a_negative_int)
	TEST(global_divide_when_passing_a_negative_int)


/*	
	
	
	TEST()
	TEST()

*/

END_SUITE







