class WordDictionary {
public:
    bool terminal;
    WordDictionary* children[26];
    WordDictionary() {
        terminal = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }

    void addWord(string word) {
        WordDictionary* node = this;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new WordDictionary;
            }
            node = node->children[idx];
        }
        node->terminal = true;
    }

    bool searchWord(string& word, int i, WordDictionary* root) {
        if (!root) {
            return false;
        }
        if (i == word.size()) {
            return root->terminal;
        }
        if (word[i] != '.') {
            int idx = word[i] - 'a';
            if (!root->children[idx])
                return false;
            return searchWord(word, i + 1, root->children[idx]);
        }
        for (int j = 0; j < 26; j++) {
            if(searchWord(word,i+1,root->children[j])){
                return true;
            }
        }
        return false;
    }

    bool search(string word) { return searchWord(word,0,this); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */