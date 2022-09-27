class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_set<int> visited;
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // check for bi-directional edges, map <key, set?> (cycle)
        // check if each node is < numCourses
        
        // first make into adj list
        for(auto courses : prerequisites){
            adj[courses[0]].push_back(courses[1]);
        }
        
        // dfs, cur must be empty for it to return true
        for (int i = 0; i < numCourses; i++){
            if (!dfs(i)) return false;
        }
        
        return true;
        
    }
    
    bool dfs(int course){
        if (visited.find(course) != visited.end()) return false;
        if (adj[course].empty()) return true;
        visited.insert(course);
        for (auto pre : adj[course]){
            if (dfs(pre) == false) return false;
        }
        visited.erase(course);
        adj[course] = {};
        return true;
    }
};