/**
 * @param {number} amount
 * @param {number[]} coins
 * @return {number}
 */
var change = function(amount, coins) {
    const sortedCoins = coins.sort((a, b) => a - b);
    
    const dp = new Array(amount + 1).fill(0);
    dp[0] = 1;
    
    for (let i = 0; i < coins.length; i++) {
        const coin = coins[i];
        for (let j = coin; j <= amount; j++) {
            
            dp[j] += dp[j - coin];
        }
    }
    
    return dp[amount];
};