class LRUCache{

struct node {
    int key;
    int value;
    node *prev;
    node *next;
    node(int k, int val): prev(NULL), next(NULL), key(k), value(val) {};
};

private:
    map<int, node*> dllist; // map the key to the node in double linked list
    int capacity;
    // head & tail do not store any value
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        dllist.clear();
        // intialization
        head->next = tail;
        head->prev = tail;
        tail->prev = head;
        tail->next = head;
    }
    
    void moveToHead(node *p)
    {
        if(p == head->next)
        {
            return;
        }
        else
        {
            // original position
            p->prev->next = p->next;
            p->next->prev = p->prev;
            // new position
            p->prev = head;
            p->next = head->next;
            head->next = p;
            p->next->prev = p;
        }
    }
    
    void insertToHead(node *p)
    {
        if(head->next == tail) // empty list
        {
            p->next = tail;
            tail->prev = p;
            p->prev = head;
            head->next = p;
        }
        else
        {
            p->prev = head;
            p->next = head->next;
            head->next = p;
            p->next->prev = p;
        }
    }
    
    void deleteTailNode(node *p)
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
    }
    
    int get(int key) {
        /*  
            not found, return -1
            exist, return value, move to head
        */
        //map<int, node*>::iterator p = dllist.begin();
        
        // not found
        if(dllist.find(key) == dllist.end())
        {
            return -1;
        }
        else
        {
            node *p = dllist[key]; // find the node
            moveToHead(p);
            return p->value;
        }
        
    }
    
    void set(int key, int value) {
        /*
            exist, change value, move to head
            not found, check cache capacity
                if not full, insert to head
                if full, delete the tail(least recently used), insert to head
        */
        if(dllist.find(key) != dllist.end())
        {
            dllist[key]->value = value;
            node *p = dllist[key];
            moveToHead(p);
        }
        else
        {
            // full
            if(dllist.size() == capacity)
            {
                node *p = tail->prev;
                // delete node from map
                dllist.erase(p->key);
                deleteTailNode(p); 
            }
            node *q = new node(key, value);
            dllist[key] = q; // Add node to map
            insertToHead(q);

        }
    }
};