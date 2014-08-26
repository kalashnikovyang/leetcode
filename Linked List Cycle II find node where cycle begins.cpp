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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return  NULL;
        if(head->next == NULL) return NULL;
        ListNode *fast = head;
        ListNode *slow = head;
        
        // detect whether has cycle first
        bool hasCycle = false;
        map<ListNode*, bool> exist;
        while(fast)
        {
            if(exist.find(fast) == exist.end())
            {
                exist[fast] = true;
            }
            else
            {
                hasCycle = true;
                break;
            }
            fast = fast->next;
        }
        if(!hasCycle) return NULL;
        
        // find cycle begins' node
        fast = head;
        while(1)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) break;
        }
        
        fast = head;
        while(fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
        
    }
};