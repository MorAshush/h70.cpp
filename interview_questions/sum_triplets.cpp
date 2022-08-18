#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

set<vector<int>> threeSum(vector<int> nums) 
    {
        set<vector<int>> set;
        int size = nums.size();
        
        sort(nums.begin(), nums.end());

        for(int i = 0; i < size; ++i)
        {
            vector<int> triplet;
            triplet.push_back(nums[i]);

            int leftIndex = i + 1;
            int rightIndex = size - 1;
            
            while(rightIndex > leftIndex)
            {
                int threeSum = nums[i] + nums[leftIndex] + nums[rightIndex];

                if(threeSum == 0)
                {
                    triplet.push_back(nums[leftIndex]);
                    triplet.push_back(nums[rightIndex]);
                    sort(triplet.begin(), triplet.end());
                    set.insert(triplet);
                    break;
                }
                else if(threeSum > 0)
                {
                    --rightIndex;
                }
                else if(threeSum < 0)
                {
                    ++leftIndex;
                }
            }
        }

        return set;
    }
/*
set<vector<int>> threeSum(vector<int> const& nums) 
    {
        set<vector<int>> set;
        int size = nums.size();
        
        for(int i = 0; i < size; ++i)
        {
            int tripletSum = 0;

            for(int j =  i+1; j < size; ++j)
            {
                for(int k = j+1; k < size; ++k)
                {
                    tripletSum = nums[i] + nums[j] + nums[k];
                    if(tripletSum == 0)
                    {
                        vector<int> triplet{nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end());
                        set.insert(triplet);
                    }
                }
            }
        }

        return set;
    }
*/
    int main()
    {
        vector<int> nums{0, 1, 1};

        threeSum(nums);
    
        return 0;
    }