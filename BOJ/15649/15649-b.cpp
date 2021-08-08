#include <iostream>

bool hasUsed[9];
int arr[9];

void dfs(int n, int m, int cur)
{
    if (cur == m)
    {
        for (int i = 0; i < m; i++)
        {
            std::cout << arr[i] << ' ';
        }
        std::cout << '\n';
        return;
    }

    if (cur > m)
    {
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (hasUsed[i])
        {
            continue;
        }
        hasUsed[i] = true;
        arr[cur] = i;
        dfs(n, m, cur + 1);
        hasUsed[i] = false;
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    dfs(n, m, 0);

    return 0;
}