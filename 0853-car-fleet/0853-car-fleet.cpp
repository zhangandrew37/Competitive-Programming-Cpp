class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> st;
        map<int, double> fleets; // pos -> speed;
        
        for (int i = 0; i < position.size(); i++){
            fleets[position[i]] = (target-position[i])/(double)speed[i];
        }
        
        for (auto &[pos, time] : fleets){
            while (!st.empty() && time >= st.top()) {
                st.pop();
            }
            st.push(time);
        }
        
        return st.size();
    }
};

/* 

[10,8,0,5,3]
[2,4,1,1,3]

10 -> 12 -> 14 -> 16
8  -> 12 -> 14 -> 16

0  ->  1 ->  2

5  ->  6 ->  7 -> ...

3  ->  6 ->  7

approach 1: reduce fleets into one position with the lowest speed
<pos, speed>

fleet[pos] = speed;

fleet[12] = 2
fleet[1] = 1
fleet[6] = 1

approach 2: sort + monotonic stack

[0, 3, 5, 8, 10]
[1, 3, 1, 4, 2 ]

p : time
0 : 12
x : 5
3 : 4
5 : 7
8 : 1
10: 1

[12,4]

ex.2

10
[6,8]
[3,2]

approach 3 : don't need stack, just keep track of cnt, cur

*/