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
            bool dup = false;
            while (curr->next && curr->val == curr->next->val)
            {
                // cout << "deleting...\n";
                dup = true;
                ListNode* tmp = curr->next->next;
                delete curr->next;
                curr->next = tmp;
            }
            if (dup)
            {
                dup = false;
                if (curr->next == NULL)
                {
                    // cout << "deleting last...\n";
                    curr = head;
                    if (head->next == NULL) head = NULL;
                    else
                    {
                        while(curr->next && curr->next->next)
                        {
                            curr = curr->next;
                        }
                        curr->next = NULL;     
                    }          
                }
                else
                {
                    // cout << "deleting remaining...\n";
                    curr->val = curr->next->val;
                    ListNode* tmp = curr->next->next;
                    delete curr->next;
                    curr->next = tmp;
                }
                
            }
            else
            {
                curr = curr->next;
            }
        }
        return head;
    }
};