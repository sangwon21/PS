#include <iostream>
#include <algorithm>

int n, m;
int arr[9];
int tmp[9];
bool hasUsed[9];

void traverse(int count)
{
    if (count == m)
    {
        for (int i = 0; i < m; i++)
        {
            std::cout << tmp[i] << ' ';
        }
        std::cout << '\n';
    }

    for (int i = 0; i < n; i++)
    {
        if (hasUsed[i] == false)
        {
            hasUsed[i] = true;
            tmp[count] = arr[i];
            traverse(count + 1);
            hasUsed[i] = false;
        }
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

    traverse(0);

    return 0;
}