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
        if(!head) return head;
        
        ListNode* res = head;
       if (head->next){
            res = reverseList(head->next);
            head->next->next = head;
       }
        head->next = nullptr;
        return res;
    }
};

/*

1 -> 2 -> 3 -> 4 -> 5 -> null
res = ..

1 -> nullptr > 1 -> 2 -> ...

*/