#include <iostream>
#include <vector>

using namespace std;

int n, k;
int limit;
vector<string> v;
int ans = 0;

bool charSet[26];

int countDictionary()
{
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        string target = v[i];
        bool flag = false;
        for (int j = 0; j < target.size(); j++)
        {
            if (charSet[target[j] - 'a'] == false)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            continue;
        }
        count++;
    }
    return count;
}

void dfs(int cur, int count)
{
    if (count == limit)
    {
        int result = countDictionary();
        ans = ans > result ? ans : result;
        return;
    }

    for (int i = cur; i < 26; i++)
    {
        if (charSet[i] == false)
        {
            charSet[i] = true;
            dfs(i, count + 1);
            charSet[i] = false;
        }
    }
}

int main()
{
    std::cin >> n >> k;
    if (k < 5)
    {
        cout << 0 << "\n";
        return 0;
    }
    else if (k == 26)
    {
        cout << n << "\n";
        return 0;
    }

    limit = k - 5;

    charSet['a' - 'a'] = true;
    charSet['n' - 'a'] = true;
    charSet['t' - 'a'] = true;
    charSet['i' - 'a'] = true;
    charSet['c' - 'a'] = true;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        string k = s.substr(4, s.size());
        if (k.size() == 0)
        {
            ans++;
        }
        else
        {
            v.push_back(k);
        }
    }

    dfs(0, 0);

    cout << ans << '\n';

    return 0;
}