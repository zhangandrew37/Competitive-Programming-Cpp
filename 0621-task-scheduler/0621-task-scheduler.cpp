class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        unordered_map<char, int> frq;
        for (char c : tasks) frq[c]++;
        for (auto [k,v] : frq) pq.push(v);
        int res = 0;
        
        while (!pq.empty()){
            vector<int> pushBack;
            for (int i = 0; i <= n; i++){
                if (pq.empty() && pushBack.empty()) return res;
                else if (pq.empty()){
                    res++;
                } else {
                    res++;
                    int cur = pq.top();
                    pq.pop();
                    cur--;
                    if (cur > 0) pushBack.push_back(cur);
                }
            }
            
            for (int i : pushBack) pq.push(i);
        }
        
        return res;
    }
};

/*

["A","A","A","B","B","B"]
2 2

A _ _ A _ _ A B

6 

"A","A","A","A","A","A","B","C","D","E","F","G"
6 1 1 1 1 1 1

5 0 0 4 0 0 3 0 0 2 x x 1 x x 0

*/

