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
    
    ListNode* reverseList(ListNode* head) {
        ListNode *next, *pre = nullptr;
        
        while (head){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        
        return pre;
    }
};

/*

1 -> 2 -> 3 -> 4 -> 5 -> null
   head

pre: 0 -> 2 -> 1

1 -> nullptr > 1 -> 2 -> ...

*/