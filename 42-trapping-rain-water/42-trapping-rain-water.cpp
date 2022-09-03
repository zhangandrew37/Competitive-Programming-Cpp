class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        int len = height.size();
        int maxLeft[len];
        int maxRight[len];
        
        // fill maxLeft
        int curMax = 0;
        for (int i = 0; i < len; i++){
            curMax = max(height[i], curMax);
            maxLeft[i] = curMax;
        }
        curMax = 0;
        // fill maxRight (go from reverse)
        for (int i = len - 1; i >= 0; i--){
            curMax = max(height[i], curMax);
            maxRight[i] = curMax;
        }
        
        for (int i = 0; i < len; i++){
            sum += max(0, min(maxLeft[i],maxRight[i]) - height[i]);
        }
        
        return sum;
    }
};

// [0,1,0,2,1,0,1,3,2,1,2,1]
//      1   1 2 1     1

// idea: look for prev greater and next greater
//   - can do this with 2 monotonic stacks



