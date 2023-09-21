class Solution {
public:
    bool canJump(vector<int>& nums) {
        int furthest = 0;
        for (int i = 0; i < nums.size(); i++){
            if (furthest < i) return false;
            furthest = max(furthest, nums[i] + i);
        }
        
        return true;
    }
};

/*

[2,3,1,1,4]




[3,2,1,0,4]
       


*/