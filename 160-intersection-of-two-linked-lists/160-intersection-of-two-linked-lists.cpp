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
    int getLength(ListNode *head){
        int len = 0;
        
        while(head)
        {
            len++;
            head = head->next;
        }
        
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        ListNode* A = headA;
        ListNode* B = headB;
        
        if (lenA > lenB)
        {
            while(lenA-lenB)
            {
                A = A->next;
                lenA--;
            }
        }
        else
        {
            while(lenB-lenA)
            {
                B = B->next;
                lenB--;
            }
        }
        
        while (A != B)
        {
            A = A->next;
            B = B->next;
        }
        
        return A;
    }
};