/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    //recursive: 
    ListNode* recurse(ListNode* cur, ListNode* prev){
        if (!cur) return prev;
        
        ListNode* tmp = cur->next;
        cur->next = prev;
        return recurse(tmp, cur);
    }
    
    ListNode* reverseList(ListNode* head) {
        return recurse(head, nullptr);
    }
};