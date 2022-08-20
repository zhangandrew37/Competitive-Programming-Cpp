class Solution {
public:
    
    static bool compare(const vector<int>&a, const vector<int>&b){
        return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort (intervals.begin(), intervals.end(), compare);
        vector<vector<int>> res;
        vector<int> cur = intervals[0];
        for (int i = 0; i < intervals.size() - 1; i++){
            // CASE 1: non-overlapping
            if (cur[1] < intervals[i + 1][0]){
                res.push_back(cur);
                cur = intervals[i + 1];
            // CASE 2: overlapping, check for next overlap as well
            } else{
                cur[1] = max(cur[1], intervals[i + 1][1]);
            }
        }
        
        res.push_back(cur);
        
        return res;
    }
};