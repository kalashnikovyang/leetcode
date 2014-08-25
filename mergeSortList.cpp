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
    ListNode *sortList(ListNode *head) {
        // special case
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        
        // merge sort -> O(nlogn), insert sort -> O(n^2)
        int listLen = 0;
        ListNode *start = head;
        while(start)
        {
            listLen++;
            start = start->next;
        }
        
        // find the position to cut list to two halves
        ListNode *a = head, *b;
        int halfLen = 1;
        while(halfLen < listLen/2)
        {
            halfLen++;
            a = a->next;
        }
        // at this time half list a store the last element
        b = a->next;
        a->next = NULL;
        
        // recursion merge sort
        a = head; //attention a to right position
        a = sortList(a);
        b = sortList(b);
        
        ListNode *record;
        // consider head first
        if(a->val < b->val)
        {
            record = a;
            start = a;
            a = a->next;
        }
        else
        {
            record = b;
            start = b;
            b = b->next;
        }
        while(a && b)
        {
            if(a->val < b->val)
            {
                start->next = a;
                a = a->next;
                start = start->next;
            }
            else
            {
                start->next = b;
                b = b->next;
                start = start->next;
            }
        }
        // in case one of half is empty
        while(a)
        {
           start->next = a;
           a = a->next;
           start = start->next; 
        }
        while(b)
        {
            start->next = b;
            b = b->next;
            start = start->next;
        }
        start->next = NULL;
        
        return record;
    }
};