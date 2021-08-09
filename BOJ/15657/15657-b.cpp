#include <iostream>
#include <algorithm>

int n, m;
int arr[9];
int tmp[9];

void traverse(int index, int count)
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

    for (int i = index; i < n; i++)
    {
        tmp[count] = arr[i];
        traverse(i, count + 1);
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