class Node {
public:
    int key;
    int val;
    Node* left;
    Node* right;
    Node(int k, int v) : key(k), val(v), left(NULL), right(NULL) {}
};

class LRUCache {
public:
    int c;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> cache;

    void insert(Node* node) {
        Node* curr = head->right;
        head->right = node;
        node->right = curr;
        node->left = head;
        curr->left = node;
    }

    void remove(Node* node) {
        Node* prev = node->left;
        Node* after = node->right;
        prev->right = after;
        after->left = prev;
    }

    LRUCache(int capacity) {
        c = capacity;
        cache.clear();
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->right = tail;
        tail->left = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;
        Node* node = cache[key];
        remove(node);
        insert(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->val = value;
            remove(node);
            insert(node);
        } else {
            if (cache.size() == c) {
                Node* node = tail->left;
                cache.erase(node->key);
                remove(node);
            }
            Node* node = new Node(key, value);
            insert(node);
            cache[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */