#include <iostream>
#include <vector>

using namespace std;
/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
*/

int removeElement(vector<int>& nums, int val)
{
    int size = nums.size();

    if(val >= 51 || !size)
    {
        return size;
    }

    int i = 0;
    for(int j = 0; j < size; ++j)
    {
        if(nums[j] != val)
        {
            nums[i] = nums[j];
            ++i;
        }
    }

    return i;
}


int main()
{
    vector<int> v = {10, 3, 23, 5, 10, 22, 10, 3, 9, 12, 10};

    int k = removeElement(v, 10);

    std::cout << "k is: " << k << '\n';
    std::cout << "vector:\n" ;
    for(size_t i = 0; i < v.size(); ++i)
    {
        std::cout << v[i];
        std::cout << ',';
    }
    std::cout << '\n';
    return 0;
}