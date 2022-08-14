class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
                
        vector<int> answer;
        int prefix = 1;
        int postfix = 1;
        int len = nums.size();
        
        for (int i = 0; i < len; i++){
            answer.push_back(prefix);
            prefix *= nums[i];
        }
        
        for (int i = len - 1; i >= 0; i--){
            answer[i] *= postfix;
            postfix *= nums[i];
        }
        return answer;
    }
};

// solution 1: prefix and postfix array (not O(1) space)
// solution 2: store prefix and postfix in variables (O(1) space)