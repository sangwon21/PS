#include <iostream>
#include <algorithm>

int n, m;
int arr[9];
int tmp[9];

void traverse(int cur, int count)
{
    if (count == m)
    {
        for (int i = 0; i < m; i++)
        {
            std::cout << tmp[i] << ' ';
        }
        std::cout << '\n';
        return;
    }

    for (int i = cur; i < n; i++)
    {
        tmp[count] = arr[i];
        traverse(i + 1, count + 1);
    }
}

int main()
{
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    std::sort(arr, arr + n);
    traverse(0, 0);

    return 0;
}