class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // we want the next greater than
        int len = temperatures.size();
        vector<int> answer(len, 0);
        stack<int> nextWarmer; // monotonic decreasing
        stack<int> indexes; // could make these 2 into a pair
        
        for (int i = 0; i < len; i++){
            while (!nextWarmer.empty() && temperatures[i] > nextWarmer.top()){
                int popIndex = indexes.top();
                answer[popIndex] = i - popIndex;
                nextWarmer.pop();
                indexes.pop();
            }
            
            nextWarmer.push(temperatures[i]);
            indexes.push(i);
            
        }
        
        return answer;
    }
};