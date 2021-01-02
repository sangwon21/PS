class Solution {
public:
    int dp[1001];
    int minCostClimbingStairs(vector<int>& cost) {
        
        for(int i = 0; i < 1000; i++)
        {
            dp[i] = 0;
        }
        
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(unsigned int i = 2; i < cost.size(); i++)
        {
            int tmp = dp[i - 1] > dp[i - 2] ? dp[i - 2] : dp[i - 1];
            dp[i] = tmp + cost[i];
        }
        
        int last = cost.size();
        
        return dp[last - 1] > dp[last - 2] ? dp[last - 2] : dp[last - 1]; 
    }
};