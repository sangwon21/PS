#include <iostream>
#include <string>

int n;
bool hasVisited[9];

void dfs(int count, std::string s)
{
    if (count == n)
    {
        std::cout << s << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (hasVisited[i] == false)
        {
            hasVisited[i] = true;
            dfs(count + 1, s + std::to_string(i + 1) + " ");
            hasVisited[i] = false;
        }
    }
}

int main()
{
    std::cin >> n;

    dfs(0, "");

    return 0;
}