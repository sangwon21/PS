#include <iostream>
#include <string>

char str[11];
int alphabets[26];
int length;
int answer = 0;

bool isValid(int index)
{
    return str[index - 1] != str[index];
}

void dfs(int depth)
{
    if (depth == length)
    {
        answer++;
        return;
    }

    for (int i = 0; i < 26; i++)
    {
        if (alphabets[i] > 0)
        {
            alphabets[i]--;
            str[depth] = i + 'a';
            if (depth == 0)
            {
                dfs(depth + 1);
            }
            else if (isValid(depth))
            {
                dfs(depth + 1);
            }
            str[depth] = -1;
            alphabets[i]++;
        }
    }
}

int main()
{
    std::string target;
    std::cin >> target;

    for (int i = 0; i < 26; i++)
    {
        alphabets[i] = 0;
    }

    for (int i = 0; i < target.size(); i++)
    {
        char c = target[i];
        alphabets[c - 'a']++;
    }

    length = target.size();

    dfs(0);

    std::cout << answer << std::endl;

    return 0;
}