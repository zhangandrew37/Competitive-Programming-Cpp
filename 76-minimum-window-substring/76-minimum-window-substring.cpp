class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> freq;
        for(auto c:t)
            freq[c]++;
       
        int i = 0;
        int j = 0;
        
        int minLength = INT_MAX;
        int minStart = 0;
        int counter = t.size();
        while(j<s.size())
        {
            char curr = s[j];
            if(freq[curr] > 0)          //if the curr char's freq is positive in the map then decrement counter 
                counter--;               //this is because we we consume one unique char 
            
            //we decrement the freq of curr char
                //notice that its decremented for all char whether in map or not because for all char that are not in 't' freq                   //will be negative and will never be > 0!
            
            freq[curr]--;               
            
            j++;                         
            
            //now we have consumed all the char in 't':
                //we will shrink the length of the string and discard extra char that make the length longer
                //this will true till counter == 0 because the moment we have counter > 0 we will know that we deleted 
                // a char that was needed, so its not valid substring!
            
            while(counter == 0)
            {
                if(j-i < minLength)                 //update minlength for each interation 
                {
                    minLength = j-i;
                    minStart = i;
                }
                char startChar = s[i];         
                
                //increment the freq of ith char 
                freq[startChar]++;             
                
                //now we will check if the freq of ith char is positive or not
                //notice that for all char which are not in 't' we will have -ve freq and now incrementing them will result to 
                // 0 and not greater than 0
                //the freq will be positive only for the char which are in 't' string!
                // we increment the counter as we have an useful char to take in account!
                if(freq[startChar] > 0)
                {
                    counter++;
                }
                
                i++;
            }
        }
        if(minLength!=INT_MAX)
            return s.substr(minStart,minLength);
        else
            return "";
    }
};