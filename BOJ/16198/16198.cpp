#include <iostream>

int n;
int weights[11];
bool wasted[11];
int maxValue = 0;

int calculateWeight(int index)
{
    int left = index - 1;
    for (int i = index - 1; i >= 0; i--)
    {
        if (wasted[i] == false)
        {
            left = i;
            break;
        }
    }

    int right = index + 1;
    for (int i = index + 1; i < n; i++)
    {
        if (wasted[i] == false)
        {
            right = i;
            break;
        }
    }

    return weights[left] * weights[right];
}

void dfs(int count, int sum)
{
    if (count == n - 2)
    {
        maxValue = std::max(maxValue, sum);
        return;
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (wasted[i] == false)
        {
            wasted[i] = true;
            int weight = calculateWeight(i);
            dfs(count + 1, sum + weight);
            wasted[i] = false;
        }
    }
}

int main()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> weights[i];
    }

    dfs(0, 0);

    std::cout << maxValue << '\n';

    return 0;
}