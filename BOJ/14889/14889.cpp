#include <iostream>
#include <limits.h>
#include <math.h>

int n;
bool hasIncluded[21];
int score[21][21];
int answer = INT_MAX;

int calculateDiff()
{
    int result1 = 0;
    int result2 = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (hasIncluded[i] == true && hasIncluded[j] == true)
            {
                result1 += score[i][j];
            }
            else if (hasIncluded[i] == false && hasIncluded[j] == false)
            {
                result2 += score[i][j];
            }
        }
    }

    return std::abs(result1 - result2);
}

void dfs(int count, int cur)
{
    if (count == n / 2)
    {
        int diff = calculateDiff();
        answer = answer > diff ? diff : answer;
        return;
    }

    for (int i = cur; i < n; i++)
    {
        if (hasIncluded[i] == false)
        {
            hasIncluded[i] = true;
            dfs(count + 1, i + 1);
            hasIncluded[i] = false;
        }
    }
}

int main()
{
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> score[i][j];
        }
    }

    dfs(0, 0);

    std::cout << answer << '\n';

    return 0;
}