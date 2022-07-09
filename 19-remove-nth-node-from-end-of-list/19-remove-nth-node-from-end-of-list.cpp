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
        // dummy Node
        ListNode *res = new ListNode(0, head);
        
        ListNode *l = res;
        ListNode *r = head;
        
        while (n > 0 && r != nullptr){
            r = r->next;
            n--;
        }
        
        while (r != nullptr){
            l = l->next;
            r = r->next;
        }
        
        // delete node
        l->next = l->next->next;
        return res->next;
    }
};