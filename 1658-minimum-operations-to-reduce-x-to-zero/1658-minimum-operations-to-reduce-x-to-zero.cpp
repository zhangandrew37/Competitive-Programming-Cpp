class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = 0, res = -1;
        unordered_map<int, int> prefixSum;
        prefixSum[0] = -1;
        for (int num : nums) totalSum += num;
        int target = totalSum - x;
        
        if (target == 0) return nums.size();
        
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            
            if (prefixSum.find(sum - target) != prefixSum.end()){
                res = max(res, i - prefixSum[sum - target]);
            }
            
            prefixSum[sum] = i;
            
        }
        
        return res == -1 ? -1 : nums.size() - res;
    }
};

/*

[3,2,20,1,1,3], x = 10

target = 20

[3, 5, 25]
prefixSum = 25

totalSum = 11
target = 6

[1,]

o1 : 3 -> [1,1,4,2]
o2 : 2 -> [1,1,4]

30 - x = 20

target = 20

[3,2,20,1,1,3], x = 10

prefixSum: [3,5,25,26,27,30]

[3, 5, 10, 25, 26, 27, 30]

res = max(res, i - map[sum - x])
*/