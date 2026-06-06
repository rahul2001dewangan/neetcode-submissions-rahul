class PrefixTree {
public:
    bool isTerminal;
    PrefixTree* children[26];

    PrefixTree() {
        isTerminal = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }

    void insertWord(string& word, PrefixTree* root, int i) {
        if (i == word.length()) {
            root->isTerminal = true;
            return;
        }
        int idx = word[i] - 'a';
        if (!root->children[idx]) {
            root->children[idx] = new PrefixTree();
        }
        return insertWord(word, root->children[idx], i + 1);
    }

    void insert(string word) { insertWord(word, this, 0); }

    bool searchWord(string& word, PrefixTree* root, int i) {
        if (i == word.length()) {
            return root->isTerminal;
        }
        int idx = word[i] - 'a';
        if (!root->children[idx]) {
            return false;
        }
        return searchWord(word, root->children[idx], i + 1);
    }

    bool search(string word) { return searchWord(word, this, 0); }

    bool wordStartsWith(string& word, PrefixTree* root, int i) {
        if (i == word.length()) {
            return true;
        }
        int idx = word[i] - 'a';
        if (!root->children[idx]) {
            return false;
        }
        return wordStartsWith(word, root->children[idx], i + 1);
    }

    bool startsWith(string prefix) { return wordStartsWith(prefix, this, 0); }
};

/**
 * Your PrefixTree object will be instantiated and called as such:
 * PrefixTree* obj = new PrefixTree();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */