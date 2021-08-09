#include <iostream>
#include <algorithm>

int count[9];
int arr[9];
int number[9];
int n, m;

void traverse(int selected)
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

    for (int i = 0; i < n; i++)
    {
        if (count[i] > 0)
        {
            count[i] -= 1;
            arr[selected] = number[i];
            traverse(selected + 1);
            count[i] += 1;
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

    int c = 1;
    int k = 0;
    int target = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (target == arr[i])
        {
            c++;
        }
        else
        {
            count[k] = c;
            number[k] = target;
            k++;
            target = arr[i];
            c = 1;
        }
    }

    number[k] = target;
    count[k] = c;
    n = k + 1;

    traverse(0);

    return 0;
}