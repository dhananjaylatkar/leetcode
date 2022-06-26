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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) return head;
        
        ListNode* curr = head;
        
        
        while (curr->next)
        {
            curr = curr->next;
        }
        ListNode* tail = curr;
        ListNode* original_tail = tail;
        
        curr = head;
        ListNode* next = NULL;
        
        while(curr != original_tail && curr && curr->next != original_tail)
        {
            next = curr->next;
            curr->next = next->next;
            curr = next->next;
            tail->next = next;
            next->next = NULL;
            tail = next;
            // next = curr->next;
        }
        if (next && curr->next == original_tail)
        {
            next = curr->next;
            curr->next = next->next;
            curr = next->next;
            tail->next = next;
            next->next = NULL;
            tail = next;
        }
        return head;
    }
};