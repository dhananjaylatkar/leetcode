/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;
        ListNode* curr1 = head;
        ListNode* curr2 = head;
        bool cycle = false;
        while(curr1->next && curr2->next && curr2->next->next)
        {
            curr1 = curr1->next;
            curr2 = curr2->next->next;
            if (curr1 == curr2)
            {
                cycle = true;
                break;
            }
        }
        
        if (!cycle) return NULL;
        // cout << "cycle found at " << curr1->val << endl;
        curr1 = head;
        int res = 0;
        while (curr2->next && curr1->next)
        {
            if (curr2 == curr1) return curr1;
            curr2 = curr2->next;
            curr1 = curr1->next;
        }
        
        return NULL;
        
    }
};