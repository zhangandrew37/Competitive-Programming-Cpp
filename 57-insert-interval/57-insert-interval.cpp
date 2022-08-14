class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); i++){
                // case 1: interval on the left
            if (newInterval[1] < intervals[i][0]){
                res.push_back(newInterval);
                
                for (int j = i; j < intervals.size(); j++){
                    res.push_back(intervals[j]);
                }
                return res;
                // case 2: interval to the right of cur
            } else if (newInterval[0] > intervals[i][1]){
                res.push_back(intervals[i]);
                // case 3: need to merge, update newInterval
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        
        res.push_back(newInterval); //don't pushback newInterval until done merging
        return res;
    }
};