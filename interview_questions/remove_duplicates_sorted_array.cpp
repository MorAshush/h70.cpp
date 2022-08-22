#include <iostream>
#include <vector>
#include <utility>
/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
*/


using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int size = nums.size();
    if((size == 0) || (size == 1))
    {
        return size;
    }

    int i = 0; //slow pointer/nique element pointer

    for(int j = 1; j < size; ++j)
    {
        if(nums[i] != nums[j])
        {
            ++i;
            nums[i] = nums[j];
        }
    }

    return i + 1;
}



int main()
{
    vector<int> v = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int k = removeDuplicates(v);

    std::cout << "k = " << k << '\n';

    return 0;
}