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
        
        ListNode *res = head; 
        //find length
        int len = 0;
        ListNode *tmp = head;
        while (tmp != nullptr){
            tmp = tmp->next;
            len++;
        }
                
        n = len - n;
        
        if (n == 0){
            return head->next;
        }
        
        for (int i = 1; i < n; i++){
            head = head->next;
        }
        
        ListNode *next = head->next->next;
        delete head->next;
        head->next = next;
        return res;
    }
};