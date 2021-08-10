#include <iostream>

int n, m;
int answer = 0;
int number[21];

void traverse(int idx, int sum)
{
    if (idx >= n)
    {
        return;
    }

    if (sum + number[idx] == m)
    {
        answer++;
    }

    traverse(idx + 1, sum + number[idx]);
    traverse(idx + 1, sum);
}

int main()
{
    std::cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        std::cin >> number[i];
    }

    traverse(0, 0);

    std::cout << answer << '\n';

    return 0;
}