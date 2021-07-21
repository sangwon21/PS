#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

void reverse(std::string &target, int start, std::stack<char> &s)
{
    int startPtr = start;
    int endPtr = start + s.size();

    while (startPtr < endPtr)
    {
        char changedChar = s.top();
        s.pop();
        target[startPtr] = changedChar;

        startPtr++;
    }
}

int main()
{
    std::string str;

    getline(std::cin, str);
    int startPtr = 0;
    std::stack<char> s;
    bool inParenthesis = false;

    for (int i = 0; i < str.size(); i++)
    {
        char target = str[i];
        if (target == ' ')
        {
            reverse(str, startPtr, s);
            startPtr = i + 1;
        }

        else if (target == '<')
        {
            if (!s.empty())
            {
                reverse(str, startPtr, s);
            }
            inParenthesis = true;
        }
        else if (target == '>')
        {
            startPtr = i + 1;
            inParenthesis = false;
        }
        else
        {
            if (inParenthesis == false)
            {
                s.push(target);
            }
        }
    }

    if (!s.empty())
    {
        reverse(str, startPtr, s);
    }

    std::cout << str << std::endl;
    return 0;
}