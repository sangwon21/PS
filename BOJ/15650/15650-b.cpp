#include <iostream>

int arr[9];
bool hasUsed[9];

int n, m;

void traverse(int cur, int count)
{
    if (count == m)
    {
        for (int i = 0; i < m; i++)
        {
            std::cout << arr[i] << ' ';
        }
        std::cout << '\n';
    }

    for (int i = cur; i <= n; i++)
    {
        if (hasUsed[i] == false)
        {
            hasUsed[i] = true;
            arr[count] = i;
            traverse(i, count + 1);
            hasUsed[i] = false;
        }
    }
}

int main()
{
    std::cin >> n >> m;

    traverse(1, 0);

    return 0;
}