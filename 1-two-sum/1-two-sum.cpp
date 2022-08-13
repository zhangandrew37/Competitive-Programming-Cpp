class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numsMap; 
        vector<int> indices;
        for (int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if (numsMap.find(target - nums[i]) != numsMap.end()){ //using iterator design pattern
                indices.push_back(i);
                indices.push_back(numsMap.at(diff));
                break;
            }
        numsMap[nums[i]] = i;
        }
        return indices;
    }
};

/* Given: array of integers (nums), integer (target)
- we want to find/return the indices of two numbers that add up to target

Specifications
- EXACTLY one solution
- cannot use same element twice
- can return in any order
*/
          