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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* next = slow->next;
        if (next)
        {
            slow->val = next->val;
            slow->next = next->next;
            delete next;
        }
        else
        {
            // 1 Node Linked List
            if (slow == fast) 
            {
                delete head;
                return NULL;
            }
            
            // 2 Node Linked List
            head->next = NULL;
            delete slow;
        }
        
        return head;
    }
};