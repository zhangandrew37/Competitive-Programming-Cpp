class UnionFind{
    vector<int> parent;
    vector<int> rank; // depth of each node
public: 
     int groupCount;
     UnionFind(int n): groupCount(n) {
         parent = vector<int>(n);
         rank = vector<int>(n);
     }
    void init(int x){
        parent[x] = x;
    }
    int find(int x){
        if (parent[x] != x) parent[x] = find(parent[x]); //recursively find parent
        return parent[x];
    }
    
    void unify(int x, int y){
        int xset = find(x);
        int yset = find(y);
        if (xset == yset) return; // same parent
        groupCount--; // merged
        if(rank[xset] < rank[yset]) parent[xset] = yset; // set parent of lower rank
        else if (rank[xset] > rank[yset]) parent[yset] = xset;
        else{
            parent[yset] = xset;
            rank[xset] = rank[yset] + 1;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int accountsCount = accounts.size();
        UnionFind uf(accountsCount);
        
        unordered_map<string, int> email2AccountIdx;
        for (int i = 0; i < accountsCount; i++){
            uf.init(i);
            auto &account = accounts[i];
            for(int j = 1; j < account.size(); j++){
                string &email = account[j];
                auto iter = email2AccountIdx.find(email);
                if (iter == email2AccountIdx.end()){
                    email2AccountIdx[email] = i;
                } else{
                    uf.unify(i, iter->second);
                }
            }
            
        }
        
        int mergedAccountsCount = uf.groupCount;
        vector<vector<string>> mergedAccounts(mergedAccountsCount);
        unordered_map<int, int> groupId2Idx;
        int nextIdx = 0;
        for (auto &pair : email2AccountIdx){
            const string &email = pair.first;
            int groupId = uf.find(pair.second);
            auto iter = groupId2Idx.find(groupId);
            if (iter == groupId2Idx.end()){
                groupId2Idx[groupId] = nextIdx;
                string &name = accounts[groupId][0];
                mergedAccounts[nextIdx].push_back(name);
                mergedAccounts[nextIdx].push_back(email);
                nextIdx++;
            } else{
                mergedAccounts[iter->second].push_back(email);
            }
        }
        
        for (int i = 0; i < mergedAccountsCount; i++){
            vector<string> &emailVec = mergedAccounts[i];
            sort(emailVec.begin() + 1, emailVec.end());
        }
        return mergedAccounts;
        
    }
};