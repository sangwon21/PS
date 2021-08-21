#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n, m, start;
vector<int> v[1001];
bool hasVisited[1001];

void dfs(int node)
{

    hasVisited[node] = true;
    printf("%d ", node);

    for (int i = 0; i < v[node].size(); i++)
    {
        int next = v[node][i];
        if (hasVisited[next] == false)
        {
            dfs(next);
        }
    }
}

void bfs(int node)
{
    queue<int> q;

    for (int i = 0; i <= n; i++)
    {
        hasVisited[i] = false;
    }

    q.push(node);
    hasVisited[node] = true;

    while (q.empty() == false)
    {
        int next = q.front();
        printf("%d ", next);

        q.pop();

        for (int i = 0; i < v[next].size(); i++)
        {
            int target = v[next][i];
            if (hasVisited[target] == false)
            {
                hasVisited[target] = true;
                q.push(target);
            }
        }
    }
}

int main()
{
    std::cin >> n >> m >> start;

    for (int i = 0; i < m; i++)
    {
        int from, to;
        scanf("%d %d", &from, &to);

        v[from].push_back(to);
        v[to].push_back(from);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(v[i].begin(), v[i].end());
    }

    dfs(start);
    printf("\n");
    bfs(start);

    return 0;
}