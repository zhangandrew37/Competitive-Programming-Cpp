class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        
        // fill adj list and indegree
        for (auto pre : prerequisites){
            int a = pre[0], b = pre[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        
        // toplogical sort
        queue<int> q;
        
        // push back all leaves (courses that have no dependencies)
        for (int i = 0; i < numCourses; i++){
            if (indegree[i] == 0) q.push(i);
        }
        
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            res.push_back(cur);
            
            for (auto nbr : adj[cur]){
                indegree[nbr]--;
                if (indegree[nbr] == 0) q.push(nbr);
            }
        }
                
        if (res.size() == numCourses) return res;
        return {};
    }
};

/*

0: 
1: 0
2: 0
3: 1 2

*/