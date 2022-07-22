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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(-300, head);
        ListNode* curr = dummy;
        
        while (curr->next && curr->next->val < x)
        {
            curr = curr->next;
        }
        ListNode* swap = curr->next;
        ListNode* s_prev = curr;
        while(swap)
        {
            if (swap->val >= x)
            {
                swap = swap->next;
                s_prev = s_prev->next;
            }
            else
            {
                ListNode* next = curr->next;
                s_prev->next = swap->next;
                curr->next = swap;
                
                ListNode* s_next = swap->next;
                swap->next = next;
                
                curr = swap;
                swap = s_next;
                
            }
        }
        return dummy->next;
        
    }
};