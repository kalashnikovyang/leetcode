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
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        
        ListNode *pri = head;
        ListNode *cur = head->next;
        
        int curMax = head->val;
        while(cur!=NULL)
        {
            if(cur->val > curMax)
            {
                curMax = cur->val;
                pri = cur;
                cur = cur->next;
            }
            else
            {
                // insert curNode in the right position, from head to prior
                ListNode *newNode = new ListNode(cur->val); //store the value;
                ListNode *temp = head; 
                // first consider head, find the insert
                if(head->val > cur->val)
                {
                    newNode->next = head;
                    head = newNode;
                }
                else
                {
                    while(temp->next->val < cur->val && temp != pri) // from head to prior
                    {
                        temp = temp->next;
                    }
                    // insert curNode after temp
                    newNode->next = temp->next;
                    temp->next = newNode;
                    
                    // delete curNode
                    temp = cur;
                    pri->next = cur->next;
                    delete temp;
                    cur = pri->next;
                }
            }
        }
        return head;
        
    }
};