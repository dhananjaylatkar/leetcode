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
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        stack<ListNode*> st;
        
        while (curr)
        {
            st.push(curr);
            curr = curr->next;
        }
        
        curr = head;
        
        while(curr)
        {
            if (curr->val != st.top()->val) return false;
            curr = curr->next;
            st.pop();
        }
        return true;
    }
};