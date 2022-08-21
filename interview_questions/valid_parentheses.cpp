#include <iostream>
#include <string>
#include <stack>


using namespace std;

bool check_match(char a, char b)
{
    if(a == '[' && b != ']')
    {
        return false;
    }
    else if(a == '{' && b != '}')
    {
        return false;
    }
    else if(a == '(' && b != ')')
    {
        return false;
    }

    return true;
}

bool is_valid_perantheses(string str)
{
    stack<char> parenthesesStack;

    for(size_t i = 0; i < str.length(); ++i)
    {
        if((str[i] == '[') | (str[i] == '{') | (str[i] == '('))
        {
            parenthesesStack.push(str[i]);
        }
        else
        {
            if(!parenthesesStack.size())
            {
                return false;
            }

            char top = parenthesesStack.top();
            bool result = check_match(top, str[i]);
            if(!result)
            {
                return false;
            }
            else
            {
                parenthesesStack.pop();
            }
        }
    }

    if(parenthesesStack.size())
    {
        return false;
        std::cout << "stack size is : " << parenthesesStack.size() << '\n';
    }

    return true;
}

int main()
{
    string p = "{{(())}}[][";
    bool result = is_valid_perantheses(p);

    if(result)
    {
        std::cout << "true\n";
    }
    else
    {
        std::cout << "false\n";
    }

    return 0;
}