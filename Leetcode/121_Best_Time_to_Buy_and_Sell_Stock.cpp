#include <iostream>
class Solution {
public:
    vector<int> profit;
    int maxProfit(vector<int>& prices) {
        profit.push_back(-prices[0]);
        for(unsigned int i = 1; i < prices.size(); i++)
        {
            int maxNum = -prices[i];
            for(int j = i - 1; j >= 0; j--)
            {
                if(maxNum < prices[i] - prices[j])
                {
                    maxNum = prices[i] - prices[j];
                }
            }
            profit.push_back(maxNum);
        }
        int maxNum = profit[0];
        for(unsigned int i = 1; i < profit.size(); i++)
        {
            if(maxNum < profit[i])
            {
                maxNum = profit[i];
            }
        }
        if(maxNum < 0)
        {
            maxNum = 0;
        }
        return maxNum;
    }
};