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
    void reorderList(ListNode *head) {
        
        if(head == NULL) return;
        if(head->next == NULL) return;
        
        // use fast & slow pointers to find the middle
        ListNode *p = head;
        ListNode *q = head;
        while(q->next && q->next->next)
        {
            p = p->next;
            q = q->next->next;
        }
        ListNode *r = p;
        p = p->next;
        r->next = NULL; // cut into 2 pieces
        
        // reverse list from middle->next to end
        q = p->next;
        // in case list only has 2 nodes
        if(q) r = q->next;
        p->next = NULL;
        while(q)
        {
            q->next = p;
            p = q;
            q = r;
            if(r) r = r->next;
        }
        
        // mix 2 pieces head & p together 
        q = head;
        while(p && q)
        {
            r = q->next;
            q->next = p;
            q = r;
            r = p->next;
            p->next = q;
            p = r;
        }
        
        
    }
};