#include <iostream>
#include <vector>

/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
*/

using namespace std;

int searchInsert(vector<int>& nums, int target)
{
    size_t size = nums.size();
    size_t i = 0;
    for(i = 0; i < size; ++i)
    {
        if(target <= nums[i])
        {
            return i;
        }
    }

    return i; 
}



int main()
{
    vector<int> v = {-1, 0, 22, 30, 41, 55, 70};
    int result = searchInsert(v, 80);

    std::cout << "index : " << result << '\n';
    return 0;
}
