#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int maxArea(vector<int>& height)
{
    size_t vecSize = height.size();
    if(vecSize == 2)
    {
        return std::min(height[0], height[1]);
    }
    int maxArea = 0;
    for(size_t i = 0; i < vecSize; ++i)
    {
        for(size_t j = i + 1; j < vecSize; ++j)
        {
            int lowerBar = std::min(height[i], height[j]);
            int curArea = (j - i) * lowerBar;
            if(curArea > maxArea)
            {
                maxArea = curArea;
                std::cout << "max area: " << maxArea << '\n';
            }
        }

        if(i != 0)
        {
            size_t k = i;
            while(k > 0)
            {
                for(size_t  j = k - 1; k >= 0 ; --j)
                {
                    int lowerBar = std::min(height[k], height[j]);
                    int curArea = (k - j) * lowerBar;
                    if(curArea > maxArea)
                    {
                        maxArea = curArea;
                        std::cout << "max area: " << maxArea << '\n';
                    }
                    if(j == 0)
                    {
                        k = 0;
                        break;
                    }
                }
            }
        }
    }
    
    return maxArea;    
}

int main()
{
    vector<int> v = {1,8,6,2,5,10,8,3,10};
    maxArea(v);
    return 0;
}