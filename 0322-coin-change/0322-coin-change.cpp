class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        
        for (int i = 1; i <= amount; i++){
            for (int c : coins){
                if (c > i || dp[i-c] == INT_MAX) continue;
                dp[i] = min(dp[i], dp[i-c] + 1);
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};