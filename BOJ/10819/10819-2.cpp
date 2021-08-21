#include <iostream>
#include <limits.h>

int n;
int numbers[8];
int tmp[8];
bool hasUsed[8];
int answer = 0;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int calculate()
{
    int result = 0;

    for (int i = 0; i < n - 1; i++)
    {
        result += std::abs(tmp[i] - tmp[i + 1]);
    }
    return result;
}

void dfs(int index, int count)
{
    if (count == n)
    {
        int result = calculate();
        answer = answer < result ? result : answer;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (hasUsed[i] == false)
        {
            hasUsed[i] = true;
            tmp[index] = numbers[i];
            dfs(index + 1, count + 1);
            hasUsed[i] = false;
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

    dfs(0, 0);

    std::cout << answer << '\n';

    return 0;
}