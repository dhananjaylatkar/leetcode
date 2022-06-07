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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head, *nex = NULL, *prev = NULL;
        
        ListNode* tmp = head;
        int i = 0;
        
        while(tmp && i < k)
        {
            tmp = tmp->next;
            i++;
        }
        
        if (i != k) return head;
        
        i = 0;
        while(curr && i < k)
        {
            nex = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nex;
            i++;
        }
        
        if (curr)
        {
            ListNode* rest_head = reverseKGroup(nex, k);
            head->next = rest_head;
        }
        return prev;
    }
};