class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, set<string>> graph; // email to other emails under same name
        unordered_map<string, string> emailToName;
        
        for (auto account : accounts){
            string name = account[0];
            for (int i = 1; i < account.size(); i++){ // build graph; connect everything to first node
                string email = account[i];
                graph[email].insert(account[1]);
                graph[account[1]].insert(email);
                
                emailToName[email] = name;
            }
        }
        
        vector<vector<string>> res;
        set<string> visited;
        
        for (auto [email, val] : graph){
            // dfs
            if (visited.find(email) == visited.end()){
                stack<string> stack;
                stack.push(email);
                visited.insert(email);
                
                vector<string> curRes;
                curRes.push_back(emailToName[email]);
                
                while (!stack.empty()){
                    string cur = stack.top();
                    stack.pop();
                    curRes.push_back(cur);
                    for (auto edge : graph[cur]){
                        if (visited.find(edge) == visited.end()){
                            visited.insert(edge);
                            stack.push(edge);
                        }
                    }
                }
                sort(curRes.begin() + 1, curRes.end());
                res.push_back(curRes);
            }
        }
        
        return res;
    }
};

// n = # accounts, k = max number of emails per user
// T: dfs * sort :  O(nk) * N log K -> O (n * k N nlogk)
// S: graph: O(nk)