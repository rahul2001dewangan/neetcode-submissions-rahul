class PrefixTree {
public:
    bool isTerminal;
    PrefixTree* children[26];

    PrefixTree() {
        isTerminal = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }

    void insert(string word) {
        PrefixTree* node = this;
        for (char c : word) {
            int i = c - 'a';
            if (!node->children[i])
                node->children[i] = new PrefixTree();
            node = node->children[i];
        }
        node->isTerminal = true;
    }

    bool search(string word) {
        PrefixTree* node = this;
        for (char c : word) {
            int i = c - 'a';
            if (!node->children[i])
                return false;
            node = node->children[i];
        }
        return node->isTerminal;
    }

    bool startsWith(string prefix) {
        PrefixTree* node = this;
        for (char c : prefix) {
            int i = c - 'a';
            if (!node->children[i])
                return false;
            node = node->children[i];
        }
        return true;
    }
};

/**
 * Your PrefixTree object will be instantiated and called as such:
 * PrefixTree* obj = new PrefixTree();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */