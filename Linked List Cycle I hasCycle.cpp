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
    bool hasCycle(ListNode *head) {
        
        map<ListNode*,bool> exist;
        
        ListNode *p = head;
        while(p)
        {
            if(exist.find(p) == exist.end())
            {
                exist[p] = true;
            }
            else
            {
                return true;
            }
            p = p->next;
        }
        return false;
        
    }
};