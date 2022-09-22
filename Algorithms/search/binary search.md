# Binary Search

- consider edge cases:
  - two elements left
  - only 1 element to search
    - we need while (low <= high)

General rules:
- Include ALL possible answers when initialize lo & hi
- Don't overflow the mid calculation
- Shrink boundary using a logic that will exclude mid
  - optiional
- Avoid infinity loop by picking the correct mid and shrinking logic
- Always think of the case when there are 2 elements left

```cpp
int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high){
            int m = low + (high - low) / 2;
            if (nums[m] == target) {
                return m;
            } else if (nums[m] < target){
                low = m + 1;
            } else {
                high = m - 1;
            }
        }
                
        return -1;
        
    }
    ```