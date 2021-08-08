#include <iostream>

int n, m;
int arr[9];

void traverse(int cur, int count)
{
    if (count == m)
    {
        for (int i = 0; i < m; i++)
        {
            std::cout << arr[i] << ' ';
        }
        std::cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        arr[count] = i;
        traverse(i, count + 1);
    }
}

int main()
{
    std::cin >> n >> m;

    traverse(1, 0);

    return 0;
}