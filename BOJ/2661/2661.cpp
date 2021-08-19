#include <iostream>
#include <string>

int n;
std::string answer;
bool found = false;

bool check(std::string &s)
{
    int limit = s.size() / 2;
    for (int i = 1; i <= limit; i++)
    {
        // 몇개씩
        for (int j = 0; j + i * 2 <= s.size(); j++)
        {
            int start1 = j;
            int start2 = i + j;
            if (s.substr(start2, i) == s.substr(start1, i))
            {
                return false;
            }
        }
    }

    return true;
}

void dfs(std::string s)
{
    if (found)
    {
        return;
    }

    if (s.size() == n)
    {
        answer = s;
        std::cout << answer << '\n';
        found = true;
        return;
    }

    for (int i = 1; i <= 3; i++)
    {
        std::string tmp = s + std::to_string(i);
        if (check(tmp))
        {
            dfs(tmp);
        }
    }
}

int main()
{
    std::cin >> n;
    dfs("1");
    return 0;
}