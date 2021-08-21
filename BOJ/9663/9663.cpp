#include <iostream>

int n;
int row[16];
bool hasUsedColumn[16];
int answer = 0;

bool isValid(int column)
{
    for (int i = 0; i < column; i++)
    {
        if (row[i] == row[column])
        {
            return false;
        }
        else if (std::abs(column - i) == std::abs(row[i] - row[column]))
        {
            return false;
        }
    }

    return true;
}

void dfs(int column)
{
    if (column == n)
    {
        answer++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        row[column] = i;
        if (isValid(column))
        {
            dfs(column + 1);
        }
        row[column] = -1;
    }
}

int main()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        row[i] = -1;
    }
    dfs(0);

    std::cout << answer << '\n';
    return 0;
}