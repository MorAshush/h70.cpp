#include "mu_test.h"

#include "quadratic.hpp"
#include "rational.hpp"



//class function print

BEGIN_TEST(print_check_all_positive)
	
	algebra::Rational a(2, 3);
	algebra::Rational b(-1, 3);
	algebra::Rational c(3, 6);

	algebra::Quadratic q(a, b, c);
	q.print();

	ASSERT_THAT(1 != 30);

END_TEST

BEGIN_TEST(print_check_with_negative_a)

	algebra::Rational a(-2, 3);
	algebra::Rational b(1, 3);
	algebra::Rational c(3, 6);

	algebra::Quadratic q(a, b, c);
	q.print();

	ASSERT_THAT(1 != 30);

END_TEST

BEGIN_TEST(print_check_with_negative_b)

	algebra::Rational a(2, 3);
	algebra::Rational b(-1, 3);
	algebra::Rational c(3, 6);

	algebra::Quadratic q(a, b, c);
	q.print();

	ASSERT_THAT(1 != 30);

END_TEST

BEGIN_TEST(print_check_with_negative_c)

	algebra::Rational a(2, 3);
	algebra::Rational b(1, 3);
	algebra::Rational c(-3, 6);

	algebra::Quadratic q(a, b, c);
	q.print();

	ASSERT_THAT(1 != 30);

END_TEST

//class functions to get first,second and third coefficient

BEGIN_TEST(get_first_coefficient)

	algebra::Rational a(2, 3);
	algebra::Rational b(1, 3);
	algebra::Rational c(3, 6);

	algebra::Quadratic q(a, b, c);

	algebra::Rational r = q.get_first_cofefficient();

	ASSERT_THAT(r == a);	

END_TEST

BEGIN_TEST(get_second_coefficient)

	algebra::Rational a(2, 3);
	algebra::Rational b(1, 3);
	algebra::Rational c(3, 6);

	algebra::Quadratic q(a, b, c);

	algebra::Rational r = q.get_second_cofefficient();

	ASSERT_THAT(r == b);

END_TEST

BEGIN_TEST(get_third_coefficient)

	algebra::Rational a(2, 3);
	algebra::Rational b(1, 3);
	algebra::Rational c(3, 6);

	algebra::Quadratic q(a, b, c);

	algebra::Rational r = q.get_third_cofefficient();

	ASSERT_THAT(r == c);

END_TEST

//global function multiply quadratic by int

/*
BEGIN_TEST(mult_quadratic_by_int_when_zero)

END_TEST
*/

BEGIN_TEST(mult_quadratic_by_int_when_one)

	algebra::Rational a(2, 3);
	algebra::Rational b(1, 3);
	algebra::Rational c(3, 6);

	algebra::Quadratic q(a, b, c);

	int n = 1;

	algebra::Quadratic r = multiply(q, n);

	ASSERT_THAT((r.get_first_cofefficient()).get_numerator() == 2);
	ASSERT_THAT((r.get_second_cofefficient()).get_numerator() == 1);
	ASSERT_THAT((r.get_third_cofefficient()).get_numerator() == 3);


END_TEST

BEGIN_TEST(mult_quadratic_by_int_when_int_is_positive)

	algebra::Rational a(2, 3);
	algebra::Rational b(1, 3);
	algebra::Rational c(3, 6);

	algebra::Quadratic q(a, b, c);

	int n = 10;

	algebra::Quadratic r = multiply(q, n);

	ASSERT_THAT((r.get_first_cofefficient()).get_numerator() == 20);
	ASSERT_THAT((r.get_second_cofefficient()).get_numerator() == 10);
	ASSERT_THAT((r.get_third_cofefficient()).get_numerator() == 30);

END_TEST

BEGIN_TEST(mult_quadratic_by_int_when_int_is_negative)

	algebra::Rational a(-2, 3);
	algebra::Rational b(1, 3);
	algebra::Rational c(3, 6);

	algebra::Quadratic q(a, b, c);

	int n = -10;

	algebra::Quadratic r = multiply(q, n);

	ASSERT_THAT((r.get_first_cofefficient()).get_numerator() == 20);
	ASSERT_THAT((r.get_second_cofefficient()).get_numerator() == -10);
	ASSERT_THAT((r.get_third_cofefficient()).get_numerator() == -30);

END_TEST

//global function multiply quadratic by rational

/*BEGIN_TEST(mult_quadratic_by_rational_when_zero)

END_TEST*/

BEGIN_TEST(mult_quadratic_by_rational_when_one)

	algebra::Rational a(2, 3);
	algebra::Rational b(1, 3);
	algebra::Rational c(3, 6);

	algebra::Quadratic q(a, b, c);

	algebra::Rational rational(1, 1);

	algebra::Quadratic r = multiply(q, rational);

	ASSERT_THAT((r.get_first_cofefficient()).get_numerator() == 2);
	ASSERT_THAT((r.get_second_cofefficient()).get_numerator() == 1);
	ASSERT_THAT((r.get_third_cofefficient()).get_numerator() == 3);

END_TEST

BEGIN_TEST(mult_quadratic_by_rational_when_rational_is_positive)

	algebra::Rational a(2, 3);
	algebra::Rational b(1, 3);
	algebra::Rational c(3, 6);

	algebra::Quadratic q(a, b, c);

	algebra::Rational rational(5, 10);

	algebra::Quadratic r = multiply(q, rational);

	ASSERT_THAT((r.get_first_cofefficient()).get_numerator() == 10);
	ASSERT_THAT((r.get_second_cofefficient()).get_numerator() == 5);
	ASSERT_THAT((r.get_third_cofefficient()).get_numerator() == 15);

	ASSERT_THAT((r.get_first_cofefficient()).get_denumerator() == 30);
	ASSERT_THAT((r.get_second_cofefficient()).get_denumerator() == 30);
	ASSERT_THAT((r.get_third_cofefficient()).get_denumerator() == 60);

END_TEST

BEGIN_TEST(mult_quadratic_by_rational_when_rational_is_negative1)

	algebra::Rational a(2, 3);
	algebra::Rational b(1, 3);
	algebra::Rational c(3, 6);

	algebra::Quadratic q(a, b, c);

	algebra::Rational rational(-5, 10);

	algebra::Quadratic r = multiply(q, rational);

	ASSERT_THAT((r.get_first_cofefficient()).get_numerator() == -10);
	ASSERT_THAT((r.get_second_cofefficient()).get_numerator() == -5);
	ASSERT_THAT((r.get_third_cofefficient()).get_numerator() == -15);

	ASSERT_THAT((r.get_first_cofefficient()).get_denumerator() == 30);
	ASSERT_THAT((r.get_second_cofefficient()).get_denumerator() == 30);
	ASSERT_THAT((r.get_third_cofefficient()).get_denumerator() == 60);

END_TEST

BEGIN_TEST(mult_quadratic_by_rational_when_rational_is_negative2)

	algebra::Rational a(2, 3);
	algebra::Rational b(1, 3);
	algebra::Rational c(3, 6);

	algebra::Quadratic q(a, b, c);

	algebra::Rational rational(5, -10);

	algebra::Quadratic r = multiply(q, rational);

	ASSERT_THAT((r.get_first_cofefficient()).get_numerator() == -10);
	ASSERT_THAT((r.get_second_cofefficient()).get_numerator() == -5);
	ASSERT_THAT((r.get_third_cofefficient()).get_numerator() == -15);

	ASSERT_THAT((r.get_first_cofefficient()).get_denumerator() == 30);
	ASSERT_THAT((r.get_second_cofefficient()).get_denumerator() == 30);
	ASSERT_THAT((r.get_third_cofefficient()).get_denumerator() == 60);

END_TEST

//global function to add two quadratics

BEGIN_TEST(add_two_quadratics_all_coefficients_positive)

	algebra::Rational a1(2, 3); algebra::Rational a2(3, 5);
	algebra::Rational b1(1, 3);	algebra::Rational b2(10, 11);
	algebra::Rational c1(3, 6);	algebra::Rational c2(3, 8);

	algebra::Quadratic first_q(a1, b1, c1);
	algebra::Quadratic second_q(a2, b2, c2);

	algebra::Quadratic result = add_two_quadratics(first_q, second_q);

	ASSERT_THAT((result.get_first_cofefficient()).get_numerator() == 19);
	ASSERT_THAT((result.get_second_cofefficient()).get_numerator() == 41);
	ASSERT_THAT((result.get_third_cofefficient()).get_numerator() == 42);

	ASSERT_THAT((result.get_first_cofefficient()).get_denumerator() == 15);
	ASSERT_THAT((result.get_second_cofefficient()).get_denumerator() == 33);
	ASSERT_THAT((result.get_third_cofefficient()).get_denumerator() == 48);

END_TEST

BEGIN_TEST(add_two_quadratics_both_with_negative_coefficients)

	algebra::Rational a1(-2, 3); algebra::Rational a2(3, 5);
	algebra::Rational b1(1, 3);	algebra::Rational b2(-10, 11);
	algebra::Rational c1(-3, 6);	algebra::Rational c2(3, 8);

	algebra::Quadratic first_q(a1, b1, c1);
	algebra::Quadratic second_q(a2, b2, c2);

	algebra::Quadratic result = add_two_quadratics(first_q, second_q);

	ASSERT_THAT((result.get_first_cofefficient()).get_numerator() == -1);
	ASSERT_THAT((result.get_second_cofefficient()).get_numerator() == -19);
	ASSERT_THAT((result.get_third_cofefficient()).get_numerator() == -6);

	ASSERT_THAT((result.get_first_cofefficient()).get_denumerator() == 15);
	ASSERT_THAT((result.get_second_cofefficient()).get_denumerator() == 33);
	ASSERT_THAT((result.get_third_cofefficient()).get_denumerator() == 48);

END_TEST

/*
BEGIN_TEST()

END_TEST

BEGIN_TEST()

END_TEST

BEGIN_TEST()

END_TEST

BEGIN_TEST()

END_TEST

BEGIN_TEST()

END_TEST

BEGIN_TEST()

END_TEST

BEGIN_TEST()

END_TEST

BEGIN_TEST()

END_TEST
*/


BEGIN_SUITE(stamstam)

	TEST(print_check_all_positive)
	TEST(print_check_with_negative_a)
	TEST(print_check_with_negative_b)
	TEST(print_check_with_negative_c)

	TEST(get_first_coefficient)
	TEST(get_second_coefficient)
	TEST(get_third_coefficient)

	TEST(mult_quadratic_by_int_when_one)
	TEST(mult_quadratic_by_int_when_int_is_positive)
	TEST(mult_quadratic_by_int_when_int_is_negative)

	TEST(mult_quadratic_by_rational_when_one)
	TEST(mult_quadratic_by_rational_when_rational_is_positive)
	TEST(mult_quadratic_by_rational_when_rational_is_negative1)
	TEST(mult_quadratic_by_rational_when_rational_is_negative2)

	TEST(add_two_quadratics_all_coefficients_positive)
	TEST(add_two_quadratics_both_with_negative_coefficients)

END_SUITE

/*
	
	TEST(stam)
	TEST(stam)
	TEST(stam)
	TEST(stam)
	TEST(stam)
	TEST(stam)
	TEST(stam)
	TEST(stam)
	TEST(stam)
	TEST(stam)
	TEST(stam)
	TEST(stam)
	TEST(stam)
	TEST(stam)
	TEST(stam)
	TEST(stam)
	TEST(stam)
	TEST(stam)
	TEST(stam)
	TEST(stam)
	TEST(stam)
	TEST(stam)
	TEST(stam)
	TEST(stam)
	TEST(stam)
	TEST(stam)
*/