class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int area = (r - l) * min(height[r], height[l]);
        while (l < r){
            if (height[l] >= height[r]){
                // have while loop find next index to avoid unecessary calculations
                //optimization: height[r-step] > height[r]
                r--;
            } else {
                l++;
            }
            area = max(area, (r - l) * min(height[r], height[l]));
        }
        return area;
    }
};