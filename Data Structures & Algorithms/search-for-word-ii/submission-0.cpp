class Trie {
public:
    bool terminal;
    Trie* children[26];
    const string* w;

    Trie() {
        terminal = false;
        w = nullptr;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Solution {
public:
    int rows, cols;
    vector<string> ans;

    void addWord(const string& word, Trie* node) {
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
        }
        node->terminal = true;
        node->w = &word;
    }

    void dfs(int r, int c, vector<vector<char>>& board, Trie* node) {
        if (r < 0 || c < 0 || r >= rows || c >= cols)
            return;
        char ch = board[r][c];
        if (ch == '*')
            return;
        node = node->children[ch - 'a'];
        if (!node)
            return;
        if (node->terminal) {
            ans.push_back(*node->w);
            node->terminal = false;
        }
        board[r][c] = '*';
        dfs(r + 1, c, board, node);
        dfs(r - 1, c, board, node);
        dfs(r, c + 1, board, node);
        dfs(r, c - 1, board, node);
        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        rows = board.size();
        cols = board[0].size();
        Trie* root = new Trie();
        for (const string& word : words) {
            addWord(word, root);
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (root->children[board[i][j] - 'a'])
                    dfs(i, j, board, root);
            }
        }
        return ans;
    }
};