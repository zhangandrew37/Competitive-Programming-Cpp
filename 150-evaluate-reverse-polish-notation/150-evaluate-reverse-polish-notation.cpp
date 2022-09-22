class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(string token: tokens){
            if (token != "+" && token != "-" && token != "*" && token != "/"){
                int n = stoi(token); // O(1)?
                nums.push(n);
            } else {
                int first = nums.top();
                nums.pop();
                int second = nums.top();
                nums.pop();
                
                if (token == "+"){
                    nums.push(first + second);
                } else if (token == "-"){
                    nums.push(second - first);
                } else if (token == "*"){
                    nums.push(first * second);
                } else {
                    nums.push(second / first);
                }
            }
        }
        
        return nums.top();
    }
};