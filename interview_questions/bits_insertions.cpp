#include <cstdint>
#include <iostream>

int32_t insert_b_in_a(int32_t a, int32_t b, short startBit, short endBit)
{
    if(startBit >= 32 | endBit <= 0 | startBit == endBit)
    {
        return 0;
    }

    b = b << endBit;

    return a | b;
}


int main()
{
    int32_t result = insert_b_in_a(2817, 76, 7, 1);

    std::cout << "expected num is: 1100\n"; 
    std::cout << "the result number is: " << result << '\n';

    return 0;
}