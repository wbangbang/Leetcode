class LRUCache{
private:
    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int k, int v): key(k), val(v) {}
    };
    
    int maxSize;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> check;
    
    bool isFull() {
        return (check.size() >= maxSize);
    }
    
    void insertKey(int key, int value) {
        if(isFull() || check.count(key)) return;
        Node* newOne = new Node(key, value);
        if(!head) {
            head = newOne;
            tail = newOne;
        }
        else {
            tail->next = newOne;
            newOne->prev = tail;
            tail = newOne;
        }
        check[key] = newOne;//assign value to hashtable.
        return;
    }
    
    void removeHead() {
        if(!head) return;
        Node* temp = head;
        check.erase(head->key);//erase the one to be removed.
        if(head == tail) {
            head = NULL;
            tail = NULL;
        }
        else {
            head = head->next;//"head->next = head" is wrong!
            head->prev = NULL;
            temp->next = NULL;
        }
        delete temp;
    }
    
    void movetoEnd(int key) {
        if(check[key] == tail || !check.count(key)) return;
        Node* temp = check[key];
        if(temp == head) {
            head = temp->next; 
            head->prev = NULL;
        }
        else {
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
        }
        tail->next = temp;
        temp->next = NULL;
        temp->prev = tail;
        tail = temp;
    }
    
public:
    LRUCache(int capacity) {
        maxSize = capacity;
        head = NULL;
        tail = NULL;
        check.clear();
    }
    
    int get(int key) {
        if(check.count(key) == 0) return -1;
        movetoEnd(key);
        return check[key]->val;
    }
    
    void set(int key, int value) {
        if(get(key) != -1) {
            check[key]->val = value;
            //movetoEnd(key);
        } 
        else {
            if(isFull()) removeHead();
            insertKey(key, value);
        }
        return;
    }
};
