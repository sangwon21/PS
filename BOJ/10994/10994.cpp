#include <iostream>

char map[500][500];

void putSquare(int n, int y, int x)
{
    const int LIMIT = 4 * (n - 1) + 1;
    for (int i = 0; i < LIMIT; i++)
    {
        map[y][x + i] = '*';
        map[y + LIMIT - 1][x + i] = '*';
        map[y + i][x] = '*';
        map[y + i][x + LIMIT - 1] = '*';
    }
}

int main()
{
    int n;
    std::cin >> n;
    if (n == 1)
    {
        printf("*");
        return 0;
    }
    // 4n + 1 개를 그려야 한다
    for (int i = n; i > 0; i--)
    {
        putSquare(i, (n - i) * 2, (n - i) * 2);
    }

    for (int i = 0; i < 4 * (n - 1) + 1; i++)
    {
        for (int j = 0; j < 4 * (n - 1) + 1; j++)
        {
            if (map[i][j] == '*')
            {
                printf("%c", map[i][j]);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}