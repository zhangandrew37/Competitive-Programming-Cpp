class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> frq;
        for (int n : nums){
            frq[n]++;
            if (frq[n] >= 2){
                return true;
            }
        }
        return false;
    }
};

// solution 1: unordered set (hashmap)
// solution 2: frequency array