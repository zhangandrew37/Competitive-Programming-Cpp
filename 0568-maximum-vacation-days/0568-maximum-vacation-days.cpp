class Solution {
public:
    
    int dp(int city, int week, vector<vector<int>> &memo, vector<vector<int>> &days, vector<vector<int>> &adj){
        if (week >= days[0].size()) return 0;
        if (memo[city][week] != 0) return memo[city][week];
        int ans = INT_MIN;
        
        // stay at current city
        ans = max(ans, days[city][week] + dp(city, week + 1, memo, days, adj));
        
        // go to next cities
        for (int next : adj[city]){
            ans = max(ans, days[next][week] + dp(next, week + 1, memo, days, adj));
        }
        
        memo[city][week] = ans;
        
        return ans;
    }
    
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size();
        int k = days[0].size();
        vector<vector<int>> adj(n);
        vector<vector<int>> memo(n, vector<int>(k));
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (flights[i][j] == 1) adj[i].push_back(j);
            }
        }
        
        return dp(0,0, memo, days, adj);
        
    }
};

/* top down with memo

 dp[i][j] = cur_days (which is days[i][j]) + dp(nextCity, j + 1)
 i is city, j is week
 - we look for all possible next cities
 

*/