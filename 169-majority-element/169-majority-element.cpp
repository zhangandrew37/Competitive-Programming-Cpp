class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> frq;
        
        int majority = nums.size()/2 + 1;
        
        for (int n : nums){
            frq[n]++;
            if (frq[n] == majority) return n;
        }
        return 0;
    }
};

// 