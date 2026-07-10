class Node {
public:
    int key;
    int value;
    int freq;

    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        freq = 1;

        prev = nullptr;
        next = nullptr;
    }
};

class List {
public:
    Node* head;
    Node* tail;

    int size;

    List() {
        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head;

        size = 0;
    }

    void addFront(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
        size++;
    }

    void removeNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;


    }

};

class LFUCache {
public:
int capacity;
    int minFreq;

    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq =1;
    }
    void updateFreq(Node* node){
        int freq = node->freq;
        freqList[freq]->removeNode(node);
        if(freq == minFreq && freqList[freq]->size == 0 ){
            minFreq++;
        }
        node->freq=++freq;
        if( freqList.find(freq) == freqList.end()){
            freqList[freq] = new List();
        }
        freqList[freq]->addFront(node);


    }
    int get(int key) {
        if( keyNode.find(key) == keyNode.end()){
            return -1;
        }
        Node* node = keyNode[key];
        updateFreq(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (capacity == 0){
            return;
        }
        if ( keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->value = value;
            updateFreq(node);
            return;
        }
        if (keyNode.size() == capacity){
            List* list = freqList[minFreq];
            Node* node = list->tail->prev;
            list->removeNode(node);
            keyNode.erase(node->key);
            delete node;
        }
        keyNode[key] = new Node(key,value);
        minFreq =1;
        if(freqList.find(1) == freqList.end()){
            freqList[1]  = new List();
        }
        freqList[1]->addFront(keyNode[key]);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */