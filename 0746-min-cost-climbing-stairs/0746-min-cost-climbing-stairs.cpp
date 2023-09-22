class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 0;
        
        for (int i = 2; i <= n; i++){
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        
        return dp[n];
    }
};

// 10,15,20
// dp[i] is min cost to 

/*

dp[0] = 0
dp[1] = 0
dp[2] = min(0 + 10, 0 + 15)
dp[3] = min(0 + 15, 10 + 20)

*/