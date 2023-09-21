class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = nums[0];
        int res = nums[0];
        
        for (int i = 1; i < nums.size(); i++){
            curSum = max(curSum + nums[i], nums[i]);
            res = max(res, curSum);
        }
        
        return res;
    }
};

/*

int curSum = -2
int res = -2;

curSum = max(curSum + cur, cur)
res = max(res, curSum)

[-2,1,-3,4,-1,2,1,-5,4]


1

*/