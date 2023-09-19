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
        ListNode* res = nullptr;
        
        while (head){
            ListNode* next = head->next;
            head->next = res;
            res = head;
            head = next;
        }
        
        return res;
    }
};

/*

1 -> 2 -> 3 -> 4 -> 5 -> null
    head

res = null

while (cur)
    tmp = res = null
    res = cur -> tmp = 1 -> null
    cur++;

*/