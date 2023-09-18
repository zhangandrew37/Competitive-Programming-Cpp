class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int n = heights.size();
        stack<pair<int, int>> nextSt, prevSt;
        vector<int> nextLess (n, n), prevLess(n, -1);
        
        for (int i = 0; i < n; i++){
            while (!nextSt.empty() && heights[i] < nextSt.top().first){
                nextLess[nextSt.top().second] = i;
                nextSt.pop();
            }
            nextSt.push({heights[i], i});
        }
        
        for (int i = n - 1; i >= 0; i--){
            while (!prevSt.empty() && heights[i] < prevSt.top().first){
                prevLess[prevSt.top().second] = i;
                prevSt.pop();
            }
            prevSt.push({heights[i], i});
        }
        
        for (int i = 0; i < n; i++){
            int prev = prevLess[i] + 1;
            int next = nextLess[i] - 1; 
            res = max(res, heights[i] * (next - prev + 1));
        }
        
        return res;
    }
};

/*

- use monotonic stack to find next less, previous less
    - we're bound by the minimum within the range
    - so we want all of them in the range to be greater than OR EQUAL
    
[ 2,  1,  5, 6,  2,  3]

[-1, -1, -1 -1, -1, -1]
[ 3,2]

[ 1,  5,  4, 4,  5,  5]
[2,1]
*/