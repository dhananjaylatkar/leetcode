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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr = head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* left_prev = dummy;
        
        int i = 1;
        while (i < left)
        {
            left_prev = curr;
            curr = curr->next;
            i++;
        }

        ListNode* prev = NULL;
        while (i <= right)
        {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
            i++;
        }
        
        left_prev->next->next = curr;
        left_prev->next = prev;
        
        return dummy->next;
    }
};