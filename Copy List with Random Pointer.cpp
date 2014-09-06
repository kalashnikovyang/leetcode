/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        /*
            思路来自待字闺中
            deep copy，区别于shallow copy，是不一样的地址，意味着拷贝后修改不会影响oldlist
            主要考虑的是如何处理random，假设分别是oldlist和copylist，步骤如下：
            1）首先deep copy oldlist的next指针到copylist
            2）map存储oldlist的next映射
            3）预处理以备deep copy random pointer
                oldnode->next = copynode;
                copynode->random = oldnode;
            4）预处理后拷贝random pointer (考虑random为空的情况)
                copynode->random = copynode->random->random->next
            5）通过map恢复oldlist的next映射
        
        */
        
        
        if(head == NULL) return NULL;
        // deep copy -> not the same memory
        
        // store original linklist next map
        map<RandomListNode*, RandomListNode*> mapNext;
        mapNext.clear();
        RandomListNode *p = head;
        while(p)
        {
            if(mapNext.find(p) == mapNext.end())
            {
                mapNext[p] = p->next;
                p = p->next;
            }
        }
        
        // deep copy next pointer first
        RandomListNode *newHead = new RandomListNode(head->label);
        //if(head->next == NULL) return newHead; // add this line has bug
        p = newHead;
        RandomListNode *q = head;
        while(p && q)
        {
            if(q->next != NULL)
            {
                RandomListNode *pNext = new RandomListNode(q->next->label);
                p->next = pNext;
            }
            else
            {
                // last element
                p->next = NULL;
            }
            
            p = p->next;
            q = q->next;
        }
        
        // deep copy random pointer
        p = newHead;
        q = head;
        // pre-process
        while(p && q)
        {
            q->next = p;
            p->random = q;
            q = mapNext[q]; // q = q->next;
            p = p->next;
        }
        p = newHead;
        q = head;
        while(p && q)
        {
            // consider random can also be NULL
            if(p->random->random)
            {
                p->random = p->random->random->next;
            }
            else
            {
                p->random = NULL;
            }
            
            q = mapNext[q];
            p = p->next;
        }
        
        // recover old list
        q = head;
        while(q)
        {
            q->next = mapNext[q];
            q = q->next;
        }

        return newHead;
    }
};