#include <iostream>
#include <queue>

int n;

int main()
{
    std::cin >> n;

    if (n <= 9)
    {
        std::cout << n << std::endl;
        return 0;
    }

    int count = n;

    std::queue<long long> q;

    for (int i = 1; i < 10; i++)
    {
        q.push(i);
    }

    while (q.empty() == false && count != 0)
    {
        long long number = q.front();
        q.pop();

        long long limit = number % 10 - 1;

        for (int i = 0; i <= limit; i++)
        {
            long long newNumber = number * 10 + i;
            q.push(newNumber);
        }
        count--;
        if (count == 0)
        {
            std::cout << number << '\n';
            return 0;
        }
    }

    std::cout << -1 << '\n';
    return 0;
}