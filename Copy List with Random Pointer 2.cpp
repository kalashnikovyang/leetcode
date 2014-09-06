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
            第一种思路
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
            
            另外一种思路，不用借助map直接在原链表操作。
            1）将copynode插入到old node后面
            2）处理copynode的random指针 (也要注意random为空的情况)
                copynode->random = oldnode->random->next
            3）还原原链表，同时生成新的deep copy链表
                oldnode->next = oldnode->next->next;
                copynode->next = copynode->next->next;
        
        */
        
        if(head == NULL) return NULL;

        RandomListNode *p = head;
        RandomListNode *newHead = new RandomListNode(p->label);
        newHead->next = p->next;
        p->next = newHead;
        p = p->next->next;
        while(p)
        {
            RandomListNode *copyNode = new RandomListNode(p->label);
            copyNode->next = p->next;
            p->next = copyNode;
            p = p->next->next;
        }
        
        p = head;
        RandomListNode *q = p->next;
        while(p)
        {
            if(p->random)
            {
                q->random = p->random->next;
            }
            else
            {
                q->random = NULL;
            }
            p = q->next;
            if(p) q = p->next;
        }
        // recover old list, generate new list
        p = head;
        q = p->next;
        while(p)
        {
            if(p->next) p->next = p->next->next;
            if(q->next) q->next = q->next->next;
            p = p->next;
            q = q->next;
        }
        
        return newHead;
    }
};