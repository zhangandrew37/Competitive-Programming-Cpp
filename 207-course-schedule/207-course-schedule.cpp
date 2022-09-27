class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> degree(numCourses, 0);
        
        // first make into adj list
        for(auto courses : prerequisites){
            adj[courses[1]].push_back(courses[0]);
            degree[courses[0]]++;
        }
        
        queue<int> q;
        
        for (int i = 0; i < numCourses; i++){
            if (degree[i] == 0) q.push(i); // add courses w/ empty adj list to queue
        }
        
        while (!q.empty()){
            int cur = q.front(); 
            q.pop();
            numCourses--;
            
            for (auto n : adj[cur]) {
                if (--degree[n] == 0) q.push(n);
            }
        }
        
        return numCourses == 0;
        
    }
};