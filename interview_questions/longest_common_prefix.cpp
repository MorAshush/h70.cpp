#include <iostream>
#include <string>
#include <vector>

using namespace std;

string common_prefix(string a, string b)
{
    int length = min(a.length(), b.length());
    string commonPrefix;
    for(int i = 0; i < length; ++i)
    {
        if(a[i] == b[i])
        {
            commonPrefix += a[i];
        }
    }

    return commonPrefix;
}

string longestCommonPrefix(vector<string>& strs)
{
    if(strs.size() == 1)
    {
        return strs[0];
    }

    string prefix = strs[0];

    for(size_t i = 1; i < strs.size(); ++i)
    {
        prefix = common_prefix(prefix, strs[i]);
        if(prefix == "")
        {
            return prefix;
        }
    }
    
    return prefix;
}



int main()
{
    vector<string> sv{"leetcode", "let", "leets", "leetr"};
    string common = longestCommonPrefix(sv);

    std::cout << common << '\n';

    return 0;
}