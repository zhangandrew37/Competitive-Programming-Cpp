class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n - k + 1), maxLeft(n), maxRight(n);
        
        int cur = INT_MIN;
        for (int i = 0; i < n; i++){
            if (i % k == 0) {
                cur = nums[i];
            } else {
                cur = max(cur, nums[i]);
            }
            maxLeft[i] = cur;
        }
        
        cur = nums[n-1];
        for (int i = n - 1; i >= 0; i--){
            if (i % k == k - 1) {
                cur = nums[i];
            } else {
                cur = max(cur, nums[i]);
            }
            maxRight[i] = cur;
        }
        
        for (int i = 0; i <= n - k; i++){
            res[i] = max(maxRight[i], maxLeft[i + k - 1]); 
        }
        return res;
    }
};

/*

[1,3,-1 || -3,5,3 || 6,7] k = 3
 
- partition nums into segments of size k
- track maxLeft, maxRight for each index within a segment

=> 
maxLeft: [1,3,3 || -3, 5, 5 || 6, 7]
maxRight: [3, 3, -1 || 5, 5, 3 || 7, 7]

res[i] = max(maxRight[i], maxLeft[i + k - 1])

i.e. 
res[0] = max(maxRight[0], maxLeft[2])
- everything in that segment to the right
- everything in segment to the left of the right side of the window

*/