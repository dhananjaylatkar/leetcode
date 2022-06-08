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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;
        ListNode* head;
        ListNode* tail;
        ListNode* a = list1;
        ListNode* b = list2;
        if (list1->val < list2->val)
        {
            head = list1;
            tail = list1;
            a = list1->next;
        }
        else
        {
            head = list2;
            tail = list2;
            b = list2->next;
        }
        
        
        while (a && b)
        {
            if (a->val < b->val)
            {
                tail->next = a;
                tail = a;
                a = a->next;
                
            }
            else{
                tail->next = b;
                tail = b;
                b = b->next;
                
            }
        }
        
        if (a == NULL)
        {
            tail->next = b;
        }
        else
        {
            tail->next = a;
        }
        return head;
    }
};