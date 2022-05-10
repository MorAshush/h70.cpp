#include <cstddef> //size_t
#include <cstdlib> //malloc, free
#include <cstdio> // printf
#include <iostream> // std::cout
#include <cassert>

#include "first_class.hpp"

#define TRUE 1
#define FALSE 0

#define MAX_SIZE_T (-1)
#define MAX_CHARS 256

//question 1: find if an element is present in an array

bool find(int const* a_array, size_t a_size, int a_x)
{
    if(!a_array)
    {
        return 0;
    }

    for(size_t i = 0; i < a_size; ++i)
    {
        if(a_array[i] == a_x)
        {
            return 1;
        }
    }

    return 0;
}

//recoursive version:

static bool recursive_find(int const* a_arr, size_t a_size, int a_x)
{
    if( !a_size )
    {
        return 0;
    }

    if( (*(a_arr + (a_size - 1)) ) == a_x )
    {
        return 1;
    }

    return recursive_find( a_arr, --a_size, a_x );
}

bool find_rec(int const* a_arr, size_t a_size, int a_x)
{
    if(!a_arr || !a_size)
    {
        return 0;
    }

    return recursive_find(a_arr, a_size, a_x);
}


//question 2:

unsigned int count_bits_on_long(long _num)
{
    int count = 0;

    while(_num != 0)
    {
        if (_num & 1)
        {
            count++;
        }
        _num >>= 1;
    }
    return count;
}

//LUT version:

static int how_many_bits_on_char(unsigned char _ch)
{
    int count = 0;

    while(_ch != 0)
    {
        if((_ch & 1) != 0)
        {
            count++;
        }
        _ch >>= 1;
    }

    return count;
}

static void build_lut(char* a_table)
{
    int i = 0;

    for(i = 0; i < MAX_CHARS ; ++i)
    {
        a_table[i] = how_many_bits_on_char(i);
    }
}

unsigned int bits_count_lut(long a_num)
{
    static char flag;
    static char bitsOnTable[MAX_CHARS] = {0};
    int sum = 0;

    if(flag != 1)
    {
        build_lut(bitsOnTable);
        flag = 1;
    }

    while(a_num)
    {
        sum += bitsOnTable[a_num & 0xFF];
        a_num >>= 8;
    }
    
    return sum;
}

//question 3:

size_t find_elements_index(int const* _arr, size_t _arrSize, int _num)
{
    
    size_t i = 0;

    while(i < _arrSize)
    {
        if(_arr[i] == _num)
        {
            return i;
        }

        ++i;
    }

    return MAX_SIZE_T;
}

//binary search version:

size_t binary_search(int const* a_arr, size_t a_size, int a_num)
{
    int left = 0;
    int right = a_size - 1;
    int middle = 0;

    if(!a_arr)
    {
        return a_size;
    }

    while (left <= right)
    {
        middle = (left + right) / 2;

        if(a_arr[middle] == a_num)
        {
           return middle; 
        }
        else if (a_arr[middle] > a_num)
        {
          right = middle - 1;        
        }
        else
        {
         left = middle + 1;
        }
    }

    return a_size;
}

//question 4:

static int add(int a_first, int a_second)
{
    return a_first + a_second;
}
static int substract_1(int a_num)
{
    return a_num - 1;
}

/*
static int IsOdd(int a_num)
{
    return _num % 2 == 1;
}

static int Half(int a_num)
{
    return _num / 2;
}
*/

static int recursive_mult(int a_num1, int a_num2)
{
    if(a_num2 == 1)
    {
        return a_num1;
    }
    if(a_num1 == 1)
    {
        return a_num2;
    }

    return add(a_num1, recursive_mult(a_num1, substract_1(a_num2)));
}

int multiply_rec(int a_num1, int a_num2)
{
    if(!a_num1 || !a_num2)
    {
        return 0;
    } 

    size_t isNegative = 0;
    if(a_num2 < 0)
    {
        isNegative = 1;
        a_num2 = -a_num2;
    }

    int result = 0;

    /*if(a_num1 > a_num2)
    {
        result = recursive_mult(a_num1, a_num2);
    }
    else
    {
        result = recursive_mult(a_num2, a_num1);        
    }*/
    result = recursive_mult(a_num1, a_num2);

    if(isNegative == 1)
    {
        return -(result);
    }

    return result;
}

/*
static int recursive_mult(int _a, int _b, int _sum)
{
    if(_b == 0)
    {
        return _sum;
    }

    _sum = Add(_a, _sum);

    return recursive_mult(_a, _b - 1, _sum);
}

int multiply_rec(int a_num1, int a_num2)
{
    

    if(_a == 0 || _b == 0)
    {
        return 0;
    }

    if(_b < 0)
    {
        _b = -(_b);
        isNegative = 1;
    }

    int result = recursive_mult(_a, _b, 0);

    if(isNegative == 0)
    {
        return result;
    }
    else
    {
        return -result;
    }
}
*/

static bool recursive_is_even(int a_num)
{
    if(a_num == 0)
    {
        return 1;
    }

    if(a_num == 1)
    {
        return 0;
    }

    a_num = substract_1(a_num);

    return recursive_is_even(substract_1(a_num));
}

bool is_even_rec(int a_num)
{
    if(a_num < 0)
    {
        a_num = -a_num;
    }

    return recursive_is_even(a_num);
}


enum MonotonicityType monotonicity(float const* a_array, size_t a_size)
{
    float const* ptr = a_array;
    float const* end = a_array + a_size;

    int incFlag = 1;
    int strctIncFlag = 1;
    int decFlag = 1;
    int strctDecFlag = 1;

    while(ptr++ < end)
    {
        if( !(*ptr <= *(ptr + 1)) && incFlag == 1)
        {
            incFlag = 0;
        }
        else if( !(*ptr < *(ptr + 1)) && strctIncFlag == 1 )
        {
            strctIncFlag = 0;
        }
        else if( !(*ptr >= *(ptr + 1)) && decFlag == 1 )
        {
            decFlag = 0;
        }
        else if( !(*ptr > *(ptr + 1)) && strctDecFlag == 1 )
        {
            strctDecFlag = 0;
        }

    }

    if(strctIncFlag == 1)
    {
        return MONOTONIC_STRICTLY_INCREASING;
    }
    else if(incFlag == 1)
    {
        return MONOTONIC_INCREASING;
    }
    else if(strctDecFlag == 1)
    {
        return MONOTONIC_STRICTLY_DECREASING;
    }
    else if(decFlag == 1)
    {
        return MONOTONIC_DECREASING;
    }

    return MONOTONIC_NONE;
}
/*
enum MonotonicityType monotonicity(float const* a_array, size_t a_size)
{
    float const* ptr = a_array;
    float const* end = a_array + a_size;

    int incFlag = 1;
    int strctIncFlag = 1;
    int decFlag = 1;
    int strctDecFlag = 1;

    while(ptr++ < end)
    {
        if( (*ptr <= *(ptr + 1)) )
        {
            if(*ptr == *(ptr + 1) && strctIncFlag ==1 )
            {
                strctIncFlag = 0;
            }

            decFlag = 0;
            strctDecFlag = 0; 
        }
        else if( (*ptr >= *(ptr + 1)) )
        {
            if(*ptr == *(ptr + 1) && strctDecFlag == 1 ) 
            {
                strctDecFlag = 0;
            }

            incFlag = 0;
            strctIncFlag = 0;
        }
    }

    if(strctIncFlag == 1)
    {
        return MONOTONIC_STRICTLY_INCREASING;
    }
    else if(incFlag == 1)
    {
        return MONOTONIC_INCREASING;
    }
    else if(strctDecFlag == 1)
    {
        return MONOTONIC_STRICTLY_DECREASING;
    }
    else if(decFlag == 1)
    {
        return MONOTONIC_DECREASING;
    }

    return MONOTONIC_NONE;
}
*/

static bool is_prime(size_t a_num)
{
    size_t flag = 0;

    for(size_t i = 2 ; i < a_num / 2 ; ++i)
    {
        if(a_num % i == 0) 
        {
            flag = 1;
        }
    }

    if(flag == 0)
    {
        return 1;
    }

    return 0;
}
int* prime_factors(long a_num)
{
    int* factors = static_cast<int*>(malloc(2 * sizeof(int)));
    unsigned long arrSize = 2;

    size_t i = 2;
    size_t counter = 0;
    int* newFactors = 0;

    while(a_num > 0)
    {
        if(a_num % i == 0 && is_prime(i))
        {
            if(counter < arrSize)
            {
                *factors++ = i;
                ++counter;
                ++arrSize;
            }
            else
            {
                int* temp = factors;
                newFactors = static_cast<int*>(realloc(factors, (arrSize + 1) * sizeof(int)));
                if(!newFactors)
                {
                    factors = temp;
                    //return factors or 0 ??
                }
                else
                {
                    *factors++ = i;
                    ++counter;
                    ++arrSize;
                }
            }
            
            a_num = a_num / i;
        }

        ++i;
    }

    return newFactors;
}