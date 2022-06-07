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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;
        ListNode* curr = head;

        while (curr && curr->next)
        {
            if (curr->val == curr->next->val)
            {
                ListNode* tmp = curr->next->next;
                delete curr->next;
                curr->next = tmp;
            }
            else
            {
                curr = curr->next;
            }
        }
        return head;
    }
};