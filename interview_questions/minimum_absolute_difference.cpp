#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> min_difference(vector<int>& nums, vector<vector<int>>& queries)
{
    size_t queriesSize = queries.size();
    vector<int> ans;
    ans.reserve(queriesSize);

    auto calc_min_diff = [&nums](int start, int end)
    {
        int minDiff = 0;
        for(int i = start; i < end; ++i)
        {
            for(int j = i + 1; j <= end; ++j)
            {
                if(nums[i] != nums [j])
                {
                    int curDiff = std::abs(nums[i] - nums[j]);
                    if(minDiff == 0 || curDiff < minDiff)
                    {
                        minDiff = curDiff;
                    }
                }
            }
        }

        if(minDiff == 0)
        {
            return -1;
        }
        
        return minDiff;
    };
    
    for(size_t i = 0; i < queriesSize; ++i)
    {
        int startIndex = queries[i][0];
        int endIndex = queries[i][1];
        ans.push_back(calc_min_diff(startIndex, endIndex));
    }

    return ans;
}


int main()
{
    vector<int> nums = {4,5,2,2,7,10};
    vector<vector<int>> queries = {{2, 3}, {0, 2}, {0, 5}, {3, 5}};

    vector<int> ans = min_difference(nums, queries);
    for(size_t i = 0; i < ans.size(); ++i)
    {
        std::cout << ans[i] << ", ";
    }

    std::cout << '\n';

    return 0;
}