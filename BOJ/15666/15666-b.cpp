#include <iostream>
#include <algorithm>

int n, m;
int arr[9];
int count[9];
int number[9];

void traverse(int idx, int selected)
{
    if (selected == m)
    {
        for (int i = 0; i < m; i++)
        {
            std::cout << arr[i] << ' ';
        }
        std::cout << '\n';
        return;
    }

    for (int i = idx; i < n; i++)
    {
        arr[selected] = number[i];
        traverse(i, selected + 1);
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

    int c = 1;
    int target = arr[0];
    int idx = 0;

    for (int i = 1; i < n; i++)
    {
        if (target == arr[i])
        {
            c++;
        }
        else
        {
            number[idx] = target;
            count[idx] = c;
            target = arr[i];
            c = 1;
            idx++;
        }
    }

    number[idx] = target;
    count[idx] = c;
    n = idx + 1;

    traverse(0, 0);

    return 0;
}