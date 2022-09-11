#include <map>
#include <algorithm>
#include <iostream>
/*
An array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.

Your goal is to find that missing element.

Write a function:

    int solution(vector<int> &A);

that, given an array A, returns the value of the missing element.

For example, given array A such that:
  A[0] = 2
  A[1] = 3
  A[2] = 1
  A[3] = 5

the function should return 4, as it is the missing element.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [0..100,000];
        the elements of A are all distinct;
        each element of array A is an integer within the range [1..(N + 1)].
*/
using namespace std;
int solution(vector<int> &A)
{
    size_t size = A.size();
    if(size == 0)
    {
        return -1;
    }

    map<int, int> appearanceMap;
    for(int i = 1; i <= size + 1; ++i)
    {
        appearanceMap[i] = 0;
    }

    for(auto const& e : A)
    {
        ++appearanceMap[e];
    }

    for(auto const& n : appearanceMap)
    {
        if(n.second == 0)
        {
            return n.first;
        }
    }
    
    return 0;
}

int main()
{
    vector<int> v = {2, 3, 1, 5};
    int r = solution(v);

    std::cout << "missing: " << r << '\n';
    return 0;
}