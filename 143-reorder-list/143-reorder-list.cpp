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
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        stack<ListNode*> s;
        
        while (curr)
        {
            s.push(curr);
            curr = curr->next;
        }
        
        curr = head;

        while(curr && curr != s.top())
        {
            ListNode* tail = s.top();
            s.pop();
            
            ListNode* next = curr->next;
            
            if (next == tail)
            {   
                break;
            }
            curr->next = tail;
            tail->next = next;
            
            ListNode* newTail = s.top();
            
            newTail->next = NULL;
            curr = next;
        }
    }
};