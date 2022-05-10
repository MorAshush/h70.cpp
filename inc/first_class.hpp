#ifndef CLASS1_HPP
#define CLASS1_HPP

#include <cstddef>

enum MonotonicityType
{
    MONOTONIC_INCREASING,
    MONOTONIC_STRICTLY_INCREASING,
    MONOTONIC_DECREASING,
    MONOTONIC_STRICTLY_DECREASING,
    MONOTONIC_NONE    
};

/**
 * @brief check if a_needle is in the a_hayStack
 * complixity O(n)
 * @param a_hayStack pointer to an array of int
 * @param a_size size of array a_hayStack
 * @param a_needle what we look for
 * @return int 0 if a_needle not found, or 1 otherwise
 */
bool find(int const* a_hayStack, size_t a_size, int a_needle);

/**
 * @brief check if a_x is in the a_arr, recoursively
 * complixity O(n)
 * @param a_arr pointer to an array of int
 * @param a_size size of array a_arr
 * @param a_x what we look for
 * @return int 1 if found, or 0 otherwise
 */
bool find_rec(int const* a_hayStack, size_t a_size, int a_needle);

/**
 * @brief counts the number of on bits in a variable from type long
 * complixity O(n)
 * @param a_num to count bits from its binary presentation
 * @return unsigned int number of the bits that is on.
 */
unsigned int count_bits_on_long(long a_num);

/**
 * @brief at first builds a LUT to all count results for long int variables and returns the result for requested value 
 * complixity O(1)?
 * @param a_num to count bits from its binary presentation
 * @return unsigned int number of the bits that is on.
 */
unsigned int bits_count_lut(long a_num);

/**
 * @brief searches in array for an element and returns its index if present in array
 * complixity O(n)
 * @param a_arr pointer to an array of int
 * @param a_size size of array a_arr
 * @param a_num what we look for
 * @return size_t index if found, or max_value of size_t otherwise
 */
size_t find_elements_index(int const* a_arr, size_t a_size, int a_num);

/**
 * @brief performs a binary search on array for an element and returns its index if present in array
 * complixity O(log(n))
 * @param a_arr pointer to an array of int
 * @param a_size size of array a_arr
 * @param a_num what we look for
 * @return size_t index if found, or max_value of size_t otherwise
 */
size_t binary_search(int const* a_arr, size_t a_size, int a_num);

/**
 * @brief gets a number and returns true or false result if it is even
 * complixity O(n)
 * @param a_num int to check if even
 * @return int 0 if false, 1 if true
 */
bool is_even_rec(int a_num);


/**
 * @brief returns the result of a multipliance of two integers.
 * @param a_num1 and a_num2 integers to multiply
 * @return an integer result of the two numbers multiplied
 */
int multiply_rec(int a_num1, int a_num2);

MonotonicityType monotonicity(float const* a_array, size_t a_size);


#endif