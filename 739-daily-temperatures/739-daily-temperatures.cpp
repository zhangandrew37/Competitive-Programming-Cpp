class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // we want the next greater than
        int len = temperatures.size();
        vector<int> answer(len, 0);
        stack<int> nextWarmerIndices; // monotonic decreasing, keep track of indices
        
        for (int i = 0; i < len; i++){
            while (!nextWarmerIndices.empty() && temperatures[i] > temperatures[nextWarmerIndices.top()]){
                int popIndex = nextWarmerIndices.top();
                answer[popIndex] = i - popIndex; 
                nextWarmerIndices.pop();
            }
            
            nextWarmerIndices.push(i);
            
        }
        
        return answer;
    }
};