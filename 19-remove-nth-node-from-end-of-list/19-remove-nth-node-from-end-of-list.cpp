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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* curr = head;
        while(curr)
        {
            curr = curr->next;
            len++;
        }
        
        if (len == 1) {
            return NULL;
        }
        
        int from_begin = len - n;
        // cout << len << " " << from_begin << endl;
        if (from_begin == 0) // remove first elem
        {
            curr = head;
            curr = head->next;
            delete head;
            return curr;
        }
        curr = head;
        ListNode* prev = head;
        while(from_begin)
        {
            prev = curr;
            curr = curr->next;
            
            from_begin--;
        }
        // cout << prev->val<< " " << curr->val << endl;
        prev->next = curr->next;
        delete curr;
        return head;
    }
};