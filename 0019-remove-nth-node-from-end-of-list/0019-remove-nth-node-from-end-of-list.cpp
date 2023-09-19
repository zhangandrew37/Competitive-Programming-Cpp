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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* res = head;
        
        while (n > 0){
            fast = fast->next;
            n--;
        }
        
        if (!fast) return head->next;
                
        while (fast->next){
            fast = fast->next;
            head = head->next;
        }
        
        head->next = head->next->next;
        
        return res;
    }
    
};

/*

[1] 1
[1,2] 2

*/