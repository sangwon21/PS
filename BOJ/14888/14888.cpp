#include <iostream>
#include <algorithm>
#include <string>
#include <limits.h>

int n;
int number[11];
int op[4];
int opCode[10];
int minResult = INT_MAX;
int maxResult = INT_MIN;

int calculate()
{
    int sum = number[0];

    for (int i = 0; i < n - 1; i++)
    {
        int target = opCode[i];

        switch (target)
        {
        case 0:
            sum += number[i + 1];
            break;
        case 1:
            sum -= number[i + 1];
            break;
        case 2:
            sum *= number[i + 1];
            break;
        case 3:
            sum /= number[i + 1];
            break;
        }
    }

    return sum;
}

void traverse(int count)
{
    if (count == n - 1)
    {
        int result = calculate();
        minResult = minResult > result ? result : minResult;
        maxResult = maxResult < result ? result : maxResult;
        return;
    }

    for (int j = 0; j < 4; j++)
    {
        if (op[j] > 0)
        {
            op[j] -= 1;
            opCode[count] = j;
            traverse(count + 1);
            op[j] += 1;
        }
    }
}

int main()
{
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> number[i];
    }

    for (int i = 0; i < 4; i++)
    {
        std::cin >> op[i];
    }

    traverse(0);

    std::cout << maxResult << std::endl;
    std::cout << minResult << std::endl;

    return 0;
}