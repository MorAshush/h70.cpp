#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) 
{
    vector<int> indices;
    sort(nums.begin(), nums.end());
    int i = 0;
    int leftIndex = i;
    int rightIndex = nums.size() - 1;
    
    while(leftIndex < rightIndex)
    {
        if(nums[leftIndex] + nums[rightIndex] == target)
        {
            indices.push_back(leftIndex);
            indices.push_back(rightIndex);
            break;
        }
        else if(nums[leftIndex] + nums[rightIndex] > target)
        {
            --rightIndex;
        }
        else
        {
            ++leftIndex;
        }
    }
    
    return indices;
}

    int main()
    {
        vector<int> nums{3, 2, 4};

        vector<int> result = twoSum(nums, 6);

        std::cout << "result indices are: ";
        std::cout << result[0] << ',' << result[1] << '\n';
    
        return 0;
    }