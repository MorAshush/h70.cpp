#include <iostream>
#include <string>

using namespace std;

/*
Implement strStr().

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/

int str_str(string haystack, string needle)
{
    int needleLength = needle.length();
    int haystackLength = haystack.length();
    if(needleLength == 0)
    {
        return 0;
    }
    if(needleLength > haystackLength)
    {
        //?
        return -1;
    }

    for(int i = 0; i < haystackLength; ++i)
    {
        std::cout << "i = " << i << '\n';

        if(haystack[i] == needle[0])
        {
            int startIndex = i;
            int j;

            for(j = 0; j < needleLength; ++j)
            {
                if(needle[j] != haystack[i])
                {
                    --i;
                    break;
                }

                ++i;
                if(i >= haystackLength)
                {
                    std::cout << "i reached haystack length\n";
                    return -1;
                }
            }

            if(j == needleLength)
            {
                return startIndex;
            }
        }
    }

    std::cout << "end of function, returning -1\n";
    return -1;
}

int main()
{
    int index = str_str("mmmmmmmmaxima", "mm");

    std::cout << "index is: " << index << '\n';

    return 0;
}