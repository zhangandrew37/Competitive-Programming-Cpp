class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> prevNums;
        for (int n : nums){
            if (prevNums.find(n) != prevNums.end()){
                return true;
            }
            prevNums.insert(n);
        }
        return false;
    }
};