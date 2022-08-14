class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); i++){
            if (newInterval[1] < intervals[i][0]){
                res.push_back(newInterval);
                
                for (int j = i; j < intervals.size(); j++){
                    res.push_back(intervals[j]);
                }
                return res;
            } else if (newInterval[0] > intervals[i][1]){
                res.push_back(intervals[i]);
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        
        res.push_back(newInterval);
        return res;
    }
};

/* 
case 1: 

 ------
 2    5
 
 [0, 1]
 - here, newInterval[1] < curInterval[0], add rest of intervals on
 
 case 2:
 
 -----
 2   5
 
 [6,7]
 - here, newInterval[0] > curInterval[1], we can insert it here
 
 case 3: 
 else
*/