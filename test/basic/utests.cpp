#include "mu_test.h"

#include <cstddef>

#include "first_class.hpp"

#define MAX_SIZE_T (-1)



BEGIN_TEST(found_in_array_test)
	int const arr[] = { 2, 4, 5, 9, 78, 45, 21, 0, 6, 15, 11, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int num = 2;
	int result = find(arr, size, num);

	ASSERT_THAT(result == 1);

END_TEST


BEGIN_TEST(not_found_in_array)
	int const arr[] = { 2, 4, 5, 9, 78, 45, 0, 6, 15, 11, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int num = 3;
	int result = find(arr, size, num);

	ASSERT_EQUAL(result, 0);

END_TEST

BEGIN_TEST(empty_array)
	int const arr[] = { 0 };
	int size = 0;
	int num = 2;
	int result = find(arr, size, num);

	ASSERT_THAT(result == 0);

END_TEST

BEGIN_TEST(array_is_null)
	int const size = 5;
	int num = 3;
	int result = find(0, size, num);

	ASSERT_EQUAL(result, 0);

END_TEST

BEGIN_TEST(test_if_off_by_one_in_range)
	int const arr[] = { 2, 4, 5, 9, 78, 45, 21, 0, 15, 11, 6 };
	int size = sizeof(arr) / sizeof(arr[0]) - 1;
	int num = 6;
	int result = find(arr, size, num);

	ASSERT_THAT(result == 0);

END_TEST

BEGIN_TEST(is_found_when_is_first_in_array)
	int const arr[] = { 2, 4, 5, 9, 78, 45, 0, 6, 15, 11, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int num = 2;
	int result = find(arr, size, num);

	ASSERT_THAT(result == 1);

END_TEST

BEGIN_TEST(is_found_when_is_last_in_array)
	int const arr[] = { 2, 4, 5, 9, 78, 45, 0, 15, 11, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int num = 6;
	int result = find(arr, size, num);

	ASSERT_THAT(result == 1);

END_TEST

//recoursive version:

BEGIN_TEST(find_rec_in_array_test)
	int const arr[] = { 2, 4, 5, 9, 78, 45, 21, 0, 6, 15, 11, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int num = 5;
	int result = find_rec(arr, size, num);

	ASSERT_THAT(result == 1);

END_TEST


BEGIN_TEST(find_rec_not_found_in_array)
	int const arr[] = {2, 4, 5, 9, 78, 45, 0, 6, 15, 11, 6};
	int size = sizeof(arr) / sizeof(arr[0]);
	int num = 3;
	int result = find_rec(arr, size, num);

	ASSERT_EQUAL(result, 0);

END_TEST

BEGIN_TEST(find_rec_empty_array)
	int const arr[] = { 0 };
	int size = 0;
	int num = 2;
	int result = find_rec(arr, size, num);

	ASSERT_THAT(result == 0);

END_TEST

BEGIN_TEST(find_rec_array_is_null)
	int size = 5;
	int num = 3;
	int result = find_rec(0, size, num);

	ASSERT_EQUAL(result, 0);

END_TEST

BEGIN_TEST(find_rec_test_if_off_by_one_in_range)
	int const arr[] = {2, 4, 5, 9, 78, 45, 21, 0, 15, 11, 6};
	int size = sizeof(arr) / sizeof(arr[0]) - 1;
	int num = 6;
	int result = find_rec(arr, size, num);

	ASSERT_THAT(result == 0);

END_TEST

//find index:

BEGIN_TEST(find_rec_when_is_first_in_array)
	int const arr[] = {2, 4, 5, 9, 78, 45, 0, 6, 15, 11, 6};
	int size = sizeof(arr) / sizeof(arr[0]);
	int num = 2;
	int result = find_rec(arr, size, num);

	ASSERT_THAT(result == 1);

END_TEST

BEGIN_TEST(find_rec_when_is_last_in_array)
	int const arr[] = {2, 4, 5, 9, 78, 45, 0, 15, 11, 6};
	int size = sizeof(arr) / sizeof(arr[0]);
	int num = 6;
	int result = find_rec(arr, size, num);

	ASSERT_THAT(result == 1);

END_TEST


//bits counting:

BEGIN_TEST(count_bits_on_in_long_test)
	long num = 15;
	int result = count_bits_on_long(num);

	ASSERT_THAT(result > 0);
	ASSERT_EQUAL(result, 4);

END_TEST

//LUT version:

BEGIN_TEST(lut_count_bits_on_in_long_int)
	long num = 555555;
	int result = bits_count_lut(num);

	ASSERT_THAT(result > 0);
	ASSERT_EQUAL(result, 9);

END_TEST

BEGIN_TEST(lut_count_bits_in_zero)
	long num = 0;
	int result = bits_count_lut(num);

	ASSERT_EQUAL(result, 0);

END_TEST

//find element

BEGIN_TEST(find_index_in_array)
	int const arr[] = { 0, 2, 4, 5, 6 ,9, 21, 45, 78};
	int size = sizeof(arr) / sizeof(arr[0]);
	int num = 2;
	int result = find_elements_index(arr, size, num);

	ASSERT_EQUAL(result, 1);

END_TEST

BEGIN_TEST(find_index_not_in_array)
	int const arr[] = {0, 2, 4, 5, 6 ,9, 21, 45, 78};
	int size = sizeof(arr) / sizeof(arr[0]);
	int num = 10;
	int result = find_elements_index(arr, size, num);

	ASSERT_THAT(result == -1);

END_TEST

BEGIN_TEST(find_index_when_is_first_in_array)
	int const arr[] = {0, 2, 4, 5, 6 ,9, 21, 45, 78};
	int size = sizeof(arr) / sizeof(arr[0]);
	int num = 0;
	int result = find_elements_index(arr, size, num);

	ASSERT_THAT(result == 0);

END_TEST

BEGIN_TEST(find_index_when_is_last_in_array)
	int const arr[] = {0, 2, 4, 5, 6 ,9, 21, 45, 78};
	int size = sizeof(arr) / sizeof(arr[0]);
	int num = 78;
	int result = find_elements_index(arr, size, num);

	ASSERT_THAT(result == 8);

END_TEST

/* test when array in null
test when array is empty*/

//binary search version:

BEGIN_TEST(binary_search_index_in_array)
	int const arr[] = { 0, 2, 4, 5, 6 ,9, 21, 45, 78};
	int size = sizeof(arr) / sizeof(arr[0]);
	int num = 2;
	int result = binary_search(arr, size, num);

	ASSERT_EQUAL(result, 1);

END_TEST

BEGIN_TEST(binary_search_index_not_in_array)
	int const arr[] = { 0, 6, 2, 4, 5, 9, 21, 45, 78};
	size_t size = sizeof(arr) / sizeof(arr[0]);
	int num = 1;
	size_t result = binary_search(arr, size, num);

	ASSERT_EQUAL(result, size);

END_TEST

BEGIN_TEST(binary_search_index_when_is_first_in_array)
	int const arr[] = {0, 2, 4, 5, 6 ,9, 21, 45, 78};
	int size = sizeof(arr) / sizeof(arr[0]);
	int num = 0;
	int result = binary_search(arr, size, num);

	ASSERT_THAT(result == 0);

END_TEST

BEGIN_TEST(binary_search_index_when_is_last_in_array)
	int const arr[] = {0, 2, 4, 5, 6 ,9, 21, 45, 78};
	int size = sizeof(arr) / sizeof(arr[0]);
	int num = 78;
	int result = binary_search(arr, size, num);

	ASSERT_THAT(result == 8);

END_TEST

BEGIN_TEST(binary_search_index_when_null)
	int num = 78;
	int result = binary_search(0, 5, num);

	ASSERT_THAT(result == 5);

END_TEST

/* test when array in null
test when array is empty*/

//recoursive multiply:

BEGIN_TEST(multiply_rec_two_small_positive_integers)
	int num1 = 12;
	int num2 = 10;
	int result = multiply_rec(num1, num2);

	ASSERT_THAT(result > num1);
	ASSERT_THAT(result > num2);	
	ASSERT_THAT(result == 120);

END_TEST

BEGIN_TEST(multiply_rec_two_big_positive_integers)
	int num1 = 1200;
	int num2 = 105400;
	int result = multiply_rec(num1, num2);

	ASSERT_THAT(result > num1);
	ASSERT_THAT(result > num2);	
	ASSERT_THAT(result == 126480000);

END_TEST

BEGIN_TEST(multiply_rec_both_negative_integers)
	int num1 = -12;
	int num2 = -10;
	int result = multiply_rec(num1, num2);

	ASSERT_THAT(result > num1);
	ASSERT_THAT(result > num2);	
	ASSERT_THAT(result == 120);

END_TEST

BEGIN_TEST(multiply_rec_when_first_is_negative)
	int num1 = -12;
	int num2 = 10;
	int result = multiply_rec(num1, num2);

	ASSERT_THAT(result < num1);
	ASSERT_THAT(result < num2);	
	ASSERT_THAT(result == -120);

END_TEST

BEGIN_TEST(multiply_rec_when_second_is_negative)
	int num1 = 12;
	int num2 = -10;
	int result = multiply_rec(num1, num2);

	ASSERT_THAT(result < num1);
	ASSERT_THAT(result < num2);	
	ASSERT_THAT(result == -120);

END_TEST

BEGIN_TEST(multiply_rec_when_both_are_one)
	int num1 = 1;
	int num2 = 1;
	int result = multiply_rec(num1, num2);

	ASSERT_THAT(result = num1);
	ASSERT_THAT(result = num2);	
	ASSERT_THAT(result == 1);

END_TEST

BEGIN_TEST(multiply_rec_when_first_is_one)
	int num1 = 1;
	int num2 = 10;
	int result = multiply_rec(num1, num2);

	ASSERT_THAT(result > num1);
	ASSERT_THAT(result = num2);	
	ASSERT_THAT(result == 10);

END_TEST

BEGIN_TEST(multiply_rec_when_second_is_one)
	int num1 = 120;
	int num2 = 1;
	int result = multiply_rec(num1, num2);

	ASSERT_THAT(result = num1);
	ASSERT_THAT(result > num2);	
	ASSERT_THAT(result == 120);

END_TEST

BEGIN_TEST(multiply_rec_when_both_are_zero)
	int num1 = 0;
	int num2 = 0;
	int result = multiply_rec(num1, num2);

	ASSERT_THAT(result == 0);

END_TEST

BEGIN_TEST(multiply_rec_when_first_is_zero)
	int num1 = 0;
	int num2 = 20;
	int result = multiply_rec(num1, num2);

	ASSERT_THAT(result == num1);
	ASSERT_THAT(result < num2);
	ASSERT_THAT(result == 0);

END_TEST

BEGIN_TEST(multiply_rec_when_second_is_zero)
	int num1 = 15;
	int num2 = 0;
	int result = multiply_rec(num1, num2);

	ASSERT_THAT(result == num2);
	ASSERT_THAT(result < num1);
	ASSERT_THAT(result == 0);

END_TEST

//recursive is even:

BEGIN_TEST(is_even_on_even_number)
	int num = 4;
	int result = is_even_rec(num);

	ASSERT_THAT(result == 1);

END_TEST

BEGIN_TEST(is_even_on_odd_number)

	int num = 5;
	int result = is_even_rec(num);

	ASSERT_THAT(result == 0);

END_TEST

BEGIN_TEST(is_even_on_zero)

	int num = 0;
	int result = is_even_rec(num);

	ASSERT_THAT(result == 1);

END_TEST

BEGIN_TEST(is_even_on_when_equals_one)

	int num = 1;
	int result = is_even_rec(num);

	ASSERT_THAT(result == 0);

END_TEST

//monotonicity question:
BEGIN_TEST(monotonicity_check_when_monotonic_increasing)

	float const array[] = {2.5, 2.5, 3.6, 7.8, 7.8, 9.1, 10.2, 11.6, 11.6};
	size_t size = sizeof(array) / sizeof(*array);

	int result = static_cast<int>( monotonicity(array, size) );

	printf("result is : %d\n", result);
	ASSERT_THAT(result == 0);

END_TEST

BEGIN_TEST(monotonicity_check_when_monotonic_strictly_increasing)

	float const array[] = {2.5, 3.6, 7.8, 9.1, 10.2, 11.6, 12.5, 13.4};
	size_t size = sizeof(array) / sizeof(*array);

	int result = static_cast<int>( monotonicity(array, size) );

	ASSERT_THAT(result == 1);

END_TEST

BEGIN_TEST(monotonicity_check_when_monotonic_decreasing)
	
	float const array[] = {13.4, 13.4, 12.5, 11.6, 11.6, 10.2, 9.1, 7.8, 7.8};
	size_t size = sizeof(array) / sizeof(*array);

	int result = static_cast<int>( monotonicity(array, size) );

	ASSERT_THAT(result == 2);

END_TEST

BEGIN_TEST(monotonicity_check_when_monotonic_strictly_decreasing)

	float const array[] = {13.4, 12.5, 11.6, 10.6, 10.2, 9.1, 7.8, 7.6, 4.5, 3.2, 1.2};
	size_t size = sizeof(array) / sizeof(*array);

	int result = static_cast<int>( monotonicity(array, size) );

	printf("result is : %d\n", result);


	ASSERT_THAT(result == 3);

END_TEST

BEGIN_TEST(monotonicity_check_when_no_monotonicity)

	float const array[] = {13.4, 12.5, 4.2, 10.6, 10.2, 0.3, 7.8, 7.6, 4.5, 3.2, 1.2};
	size_t size = sizeof(array) / sizeof(*array);

	int result = static_cast<int>( monotonicity(array, size) );

	ASSERT_THAT(result == 4);

END_TEST

BEGIN_TEST(monotonicity_check_when_all_equal)

	float const array[] = {13.4, 13.4, 13.4, 13.4, 13.4, 13.4};
	size_t size = sizeof(array) / sizeof(*array);

	int result = static_cast<int>( monotonicity(array, size) );

	printf("result is : %d\n", result);


	ASSERT_THAT(result == 0);

END_TEST


BEGIN_SUITE(test)

	TEST(found_in_array_test)
	TEST(not_found_in_array)
	TEST(empty_array)
	TEST(array_is_null)
	TEST(test_if_off_by_one_in_range)
	TEST(is_found_when_is_first_in_array)
	TEST(is_found_when_is_last_in_array)

	TEST(find_rec_in_array_test)
	TEST(find_rec_not_found_in_array)
	TEST(find_rec_empty_array)
	TEST(find_rec_array_is_null)
	TEST(find_rec_test_if_off_by_one_in_range)
	TEST(find_rec_when_is_first_in_array)
	TEST(find_rec_when_is_last_in_array)

	TEST(count_bits_on_in_long_test)

	TEST(lut_count_bits_on_in_long_int)
	TEST(lut_count_bits_in_zero)

	TEST(find_index_in_array)
	TEST(find_index_not_in_array)
	TEST(find_index_when_is_first_in_array)
	TEST(find_index_when_is_last_in_array)

	TEST(binary_search_index_in_array)
	TEST(binary_search_index_not_in_array)
	TEST(binary_search_index_when_is_first_in_array)
	TEST(binary_search_index_when_is_last_in_array)
	TEST(binary_search_index_when_null)

	TEST(multiply_rec_two_small_positive_integers)
	TEST(multiply_rec_two_big_positive_integers)
	TEST(multiply_rec_both_negative_integers)
	TEST(multiply_rec_when_first_is_negative)
	TEST(multiply_rec_when_second_is_negative)
	TEST(multiply_rec_when_both_are_one)
	TEST(multiply_rec_when_first_is_one)
	TEST(multiply_rec_when_second_is_one)
	TEST(multiply_rec_when_both_are_zero)
	TEST(multiply_rec_when_first_is_zero)
	TEST(multiply_rec_when_second_is_zero)

	TEST(is_even_on_even_number)
	TEST(is_even_on_odd_number)
	TEST(is_even_on_zero)
	TEST(is_even_on_when_equals_one)

	TEST(monotonicity_check_when_monotonic_increasing)
	TEST(monotonicity_check_when_monotonic_strictly_increasing)
	TEST(monotonicity_check_when_monotonic_decreasing)
	TEST(monotonicity_check_when_monotonic_strictly_decreasing)
	TEST(monotonicity_check_when_no_monotonicity)
	TEST(monotonicity_check_when_all_equal)





END_SUITE
