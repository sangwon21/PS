#include <string>
using namespace std;

bool checkVer[10][11];
bool checkHor[11][10];

bool isValid(int num)
{
    return 0 <= num && num <= 10;
}

struct pos{
    int x, y;
};

int solution(string dirs)
{
	int answer = 0;
    struct pos p = {5, 5};
    
    for(int i= 0; i < dirs.size(); i++)
    {
        int currentX = p.x;
        int currentY = p.y;
        printf("current X: %d currentY: %d\n", currentX - 5, currentY - 5);
        switch(dirs[i])
        {
            case 'L':
                if(isValid(currentX - 1))
                {
                    if(checkVer[currentX - 1][currentY] == false)
                    {
                        checkVer[currentX -1][currentY] = true;
                        answer += 1;
                    }
                    p.x = currentX - 1;
                }
                break;
            case 'R':
                if(isValid(currentX + 1))
                {
                    if(checkVer[currentX][currentY] == false)
                    {
                        checkVer[currentX][currentY] = true;
                        answer += 1;
                    }
                    p.x = currentX + 1;
                }
                break;
            case 'U':
                if(isValid(currentY - 1))
                {
                    if(checkHor[currentX][currentY - 1] == false)
                    {
                        checkHor[currentX][currentY - 1] = true;
                        answer += 1;
                    }
                    p.y = currentY - 1;
                }
                break;
            case 'D':
                if(isValid(currentY + 1))
                {
                    if(checkHor[currentX][currentY] == false)
                    {
                        checkHor[currentX][currentY] = true;
                        answer += 1;
                    }
                    p.y = currentY + 1;
                }
                break;
        }
    }
    
	return answer;
}