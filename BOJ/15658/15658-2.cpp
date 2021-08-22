#include <iostream>
#include <limits.h>

int op[4] = {0, 0, 0, 0};
int numbers[11];
int opArr[11];
int n;
int minValue = INT_MAX;
int maxValue = INT_MIN;

int calculate()
{
    int result = numbers[0];
    for (int i = 0; i < n - 1; i++)
    {
        switch (opArr[i])
        {
        case 0:
            result += numbers[i + 1];
            break;
        case 1:
            result -= numbers[i + 1];
            break;
        case 2:
            result *= numbers[i + 1];
            break;
        case 3:
            result /= numbers[i + 1];
            break;
        }
    }
    return result;
}

void dfs(int depth)
{
    if (depth == n - 1)
    {
        // 계산
        int result = calculate();
        minValue = std::min(result, minValue);
        maxValue = std::max(result, maxValue);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (op[i] > 0)
        {
            op[i]--;
            opArr[depth] = i;
            dfs(depth + 1);
            op[i]++;
        }
    }
}

int main()
{
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> numbers[i];
    }

    for (int i = 0; i < 4; i++)
    {
        std::cin >> op[i];
    }

    dfs(0);

    std::cout << maxValue << std::endl;
    std::cout << minValue << std::endl;

    return 0;
}