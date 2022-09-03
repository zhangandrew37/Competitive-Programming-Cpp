class Solution {
public:
    int trap(vector<int>& height) {
        
        int sum = 0;
        int len = height.size();
        int maxLeft = height[0];
        int maxRight = height[len-1];
        int l = 0;
        int r = len - 1;
        
        while (l < r){
            if (maxLeft <= maxRight){
                l++;
                maxLeft = max(maxLeft, height[l]);
                sum += maxLeft - height[l];
            } else {
                r--;
                maxRight = max(maxRight, height[r]);
                sum += maxRight - height[r];
            }
        }
        
        return sum;
    }
};

// [0,1,0,2,1,0,1,3,2,1,2,1]
//      1   1 2 1     1

// idea: look for prev greater and next greater
//   - can do this with 2 monotonic stacks



