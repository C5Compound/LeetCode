struct trie
{
    bool iskey;
    trie *next[26];
    trie() : iskey(false) { memset(next, 0, 26 * sizeof(trie*)); };
};

class Trie {
public:
    trie *root;
    Trie() {root = new trie();};
    ~Trie() {trieFree(root);};
    void insert(string &str) {
        if (str.empty()) return;
        trie *it = root;
        for (auto i : str) {
            if (it->next[i - 'a'] == NULL) {
                it->next[i - 'a'] = new trie();
            }
            it = it->next[i - 'a'];
        }
        it->iskey = true;
    }
    void trieFree(trie *it) {
        if (it == NULL) return;
        for (int i = 0; i < 26; ++i) {
            trieFree(it->next[i]);
        }
        delete it;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> vs;
        if (board.empty() || words.empty()) {
            return vs;
        }
        Trie it;
        for (auto i : words) {
            it.insert(i);
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, vs, "", it.root, i, j);
            }
        }
        return vs;
    }
    void dfs(vector<vector<char>> &board, vector<string> &vs, string str, trie *root, int x, int y) {
        char c = board[x][y];
        if ((root = root->next[c - 'a']) == NULL) return;
        if (root->iskey) {
            vs.push_back(str + c);
            root->iskey = false;
        }
        board[x][y] = '*';
        if (x + 1 < board.size() && board[x + 1][y] != '*') dfs(board, vs, str + c, root, x + 1, y);
        if (x - 1 >= 0 && board[x - 1][y] != '*') dfs(board, vs, str + c, root, x - 1, y);
        if (y + 1 < board[0].size() && board[x][y + 1] != '*') dfs(board, vs, str + c, root, x, y + 1);
        if (y - 1 >= 0 && board[x][y - 1] != '*') dfs(board, vs, str + c, root, x, y - 1);
        board[x][y] = c;
    }
};