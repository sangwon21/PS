#include <iostream>
#include <algorithm>
#include <queue>

int n;
long long answer;

void bfs()
{
    std::queue<long long> q;

    for (long long i = 0; i < 10; i++)
    {
        q.push(i);
    }

    while (q.empty() == false)
    {
        long long targetNumber = q.front();
        q.pop();
        n--;

        if (n == 0)
        {
            answer = targetNumber;
            break;
        }

        long long startNumber = targetNumber % 10 - 1;

        for (int i = 0; i <= startNumber; i++)
        {
            long long newNumber = targetNumber * 10 + i;
            q.push(newNumber);
        }
    }
}

int main()
{
    std::cin >> n;

    if (n >= 1024 || n <= 0)
    {
        std::cout << -1 << std::endl;
        return 0;
    }

    bfs();
    std::cout << answer << std::endl;

    return 0;
}