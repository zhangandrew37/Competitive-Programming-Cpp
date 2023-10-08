class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> count(n);
        vector<vector<bool>> adj(n, vector<bool>(n, false));
        
        // construct nxn adj matrix
        for (auto road : roads){
            int a = road[0], b = road[1];
            count[a]++, count[b]++;
            adj[a][b] = true;
            adj[b][a] = true;
        }
        
        // find max of all network ranks
        int res = 0;
        
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                res = max(res, count[i]+count[j]-adj[i][j]);
            }
        }
        
        return res;
    }
};

/*

0: [1,3]
1: [0,2,3]

count[i] = number of cities that are connected to city i

  0 1 2 3
0 0 1 0 1
1 1 0 1 1
2 0 1 0 0
3 1 1 0 0

*/