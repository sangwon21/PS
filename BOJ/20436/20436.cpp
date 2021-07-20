#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <math.h>

void initializeZoac(std::map<char, std::pair<int, int>> &zoac)
{
    zoac['q'] = std::pair<int, int>(0, 0);
    zoac['w'] = std::pair<int, int>(0, 1);
    zoac['e'] = std::pair<int, int>(0, 2);
    zoac['r'] = std::pair<int, int>(0, 3);
    zoac['t'] = std::pair<int, int>(0, 4);
    zoac['y'] = std::pair<int, int>(0, 5);
    zoac['u'] = std::pair<int, int>(0, 6);
    zoac['i'] = std::pair<int, int>(0, 7);
    zoac['o'] = std::pair<int, int>(0, 8);
    zoac['p'] = std::pair<int, int>(0, 9);

    zoac['a'] = std::pair<int, int>(1, 0);
    zoac['s'] = std::pair<int, int>(1, 1);
    zoac['d'] = std::pair<int, int>(1, 2);
    zoac['f'] = std::pair<int, int>(1, 3);
    zoac['g'] = std::pair<int, int>(1, 4);
    zoac['h'] = std::pair<int, int>(1, 5);
    zoac['j'] = std::pair<int, int>(1, 6);
    zoac['k'] = std::pair<int, int>(1, 7);
    zoac['l'] = std::pair<int, int>(1, 8);

    zoac['z'] = std::pair<int, int>(2, 0);
    zoac['x'] = std::pair<int, int>(2, 1);
    zoac['c'] = std::pair<int, int>(2, 2);
    zoac['v'] = std::pair<int, int>(2, 3);
    zoac['b'] = std::pair<int, int>(2, 4);
    zoac['n'] = std::pair<int, int>(2, 5);
    zoac['m'] = std::pair<int, int>(2, 6);
}

int calculateDistance(std::pair<int, int> &from, std::pair<int, int> &to)
{
    return abs(from.first - to.first) + abs(from.second - to.second);
}

int main()
{
    std::map<char, std::pair<int, int>> zoac;

    initializeZoac(zoac);

    std::pair<int, int> leftHand;
    std::pair<int, int> rightHand;

    char l;
    char r;
    std::string str;

    std::cin >> l >> r >> str;

    leftHand = zoac[l];
    rightHand = zoac[r];

    int answer = 0;

    for (int i = 0; i < str.size(); i++)
    {
        std::pair<int, int> target = zoac[str[i]];
        int x = target.first;
        int y = target.second;

        if ((x == 0 && y >= 0 && y <= 4) || (x == 1 && y >= 0 && y <= 4) || (x == 2 && y >= 0 && y <= 3))
        {
            answer += calculateDistance(leftHand, target);
            leftHand = target;
        }
        else
        {
            answer += calculateDistance(rightHand, target);
            rightHand = target;
        }
    }

    answer += str.size();

    printf("%d\n", answer);

    return 0;
}