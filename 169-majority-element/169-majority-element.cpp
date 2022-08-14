class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;
        int count = 0;
        
        for (int n : nums){
            if (n == res){
                count++;
            } else{
                if (count == 0){
                    res = n;
                    count = 1;
                } else {
                    count--;
                }
            }
        }
        
        return res;
    }
};

// 