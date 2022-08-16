#include <string>
#include <map>
#include <iostream>

class Solution {
public:
    int romanToInt(std::string const& s)
    {
        std::map<char, int> romanLetters;
        
        romanLetters['I'] = 1;
        romanLetters['V'] = 5;
        romanLetters['X'] = 10;
        romanLetters['L'] = 50;
        romanLetters['C'] = 100;
        romanLetters['D'] = 500;
        romanLetters['M'] = 1000;
        
        int size = s.length();
        int decimal = 0;
        int i = 0;

        for(i = 0; i < size - 1; i++)
        {
            int left = romanLetters[s[i]];
            int right = romanLetters[s[i+1]]; 

            if(left >= right)
            {
                decimal += left;
            }
            else
            {
                decimal += right - left;
                ++i;
            }
        }

        if(i == size - 1)
        {
            decimal += romanLetters[s[i]];
        }
       
        return decimal;
    }
};



int main()
{
    Solution sol;
    
    std::string roman = "MCMXCII";
    int result = sol.romanToInt(roman);

    std::cout << "expected: 1992\n" ;    
    std::cout << "result: " << result << '\n';
    
    return 0;
}