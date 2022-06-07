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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* res = NULL;
        while (l1 && l2)
        {
            int tmp_sum = l1->val + l2->val + carry;
            carry = tmp_sum/10;
            tmp_sum = tmp_sum%10;
            ListNode* tmp = new ListNode(tmp_sum);
            
            ListNode* curr = res;
            if (res == NULL)
            {
                res = tmp;
            }
            else
            {
                while(curr->next) curr = curr->next;
                curr->next = tmp;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* remaining = NULL;
        if (l1)
        {
            remaining = l1;
        }
        else if (l2)
        {
            remaining = l2;
        }
            
        while (remaining)
        {
            int tmp_sum = remaining->val + carry;
            carry = tmp_sum/10;
            tmp_sum = tmp_sum%10;
            ListNode* tmp = new ListNode(tmp_sum);
            ListNode* curr = res;
            if (res == NULL)
            {
                res = tmp;
            }
            else
            {
                while(curr->next) curr = curr->next;
                curr->next = tmp;
            }
            remaining = remaining->next;
        }
        
        if (carry)
        {
            ListNode* curr = res;
            ListNode* tmp = new ListNode(carry);
            while(curr->next) curr = curr->next;
            curr->next = tmp;
        }
        return res;
    }
};