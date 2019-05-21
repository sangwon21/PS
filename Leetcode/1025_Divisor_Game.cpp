#include <cmath>

class Solution {
public:
    bool dp[1001];
    bool divisorGame(int N) {
        for(int i = 0; i < 1001; i++)
        {
            dp[i] = false;
        }
        dp[1] = false;
        for(int i = 2; i <= N; i++)
        {
            for(int j = i - 1; j >= 1; j--)
            {
                if(i % j == 0 && dp[i - j] == false)
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[N];
    }
};