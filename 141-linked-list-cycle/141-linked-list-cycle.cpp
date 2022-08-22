/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *ptr = head;
        while (ptr && ptr->next){
            if (ptr->next->val == INT_MAX) return true;
            ptr->val = INT_MAX;
            ptr = ptr->next;
        }
        
        return false;
    }
};