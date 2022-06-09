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
        stack<int> st;
        
        while (curr)
        {
            st.push(curr->val);
            curr = curr->next;
        }
        
        curr = head;
        
        while(curr)
        {
            if (curr->val != st.top()) return false;
            curr = curr->next;
            st.pop();
        }
        return true;
    }
};