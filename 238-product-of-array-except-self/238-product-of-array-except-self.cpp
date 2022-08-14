class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> prefix;
        vector<int> postfix;
        prefix.push_back(1);
        postfix.push_back(1);
        
        for (int i = 0; i < len; i++){
            prefix.push_back(nums[i]*prefix[i]);
            postfix.push_back(nums[len - i - 1]*postfix[i]);
        }
        
        for (int i = 0; i <= len; i++){
            cout << "i: " << i << " " << prefix[i] << " " << postfix[i] << endl;
        }
        
        vector<int> answer;
        for (int i = 0; i < len; i++){
            cout << i << endl;
            answer.push_back(prefix[i]*postfix[len-i-1]);
        }
        return answer;
    }
};

// nums: 