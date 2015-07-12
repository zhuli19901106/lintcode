typedef struct TrieNode {
    static const int N = 26;
    
    bool isWord;
    vector<TrieNode *> child;
    
    TrieNode() {
        isWord = false;
        child.resize(N, NULL);
    }
} TrieNode;

class Solution {
public:
    Solution() {
        d.resize(4, vector<int>(2));
        d[0][0] = +1;
        d[0][1] = 0;
        
        d[1][0] = -1;
        d[1][1] = 0;
        
        d[2][0] = 0;
        d[2][1] = +1;
        
        d[3][0] = 0;
        d[3][1] = -1;
    }
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
        v.clear();
        us.clear();
        ans.clear();
        
        vector<vector<char> > &b = board;
        n = b.size();
        m = n ? b[0].size() : 0;
        if (!(n || m)) {
            return ans;
        }
        
        TrieNode *root = new TrieNode();
        for (auto it = words.begin(); it != words.end(); ++it) {
            insertWord(root, *it);
        }
        
        string s = "";
        v.resize(n, vector<bool>(m, false));
        int i, j;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                v[i][j] = true;
                s.push_back(b[i][j]);
                DFS(i, j, s, root->child[b[i][j] - 'a'], b);
                s.pop_back();
                v[i][j] = false;
            }
        }
        
        for (auto it = us.begin(); it != us.end(); ++it) {
            ans.push_back(*it);
        }
        clearTrie(root);
        return ans;
    }
private:
    int n, m;
    vector<vector<bool> > v;
    unordered_set<string> us;
    vector<string> ans;
    vector<vector<int> > d;
    
    bool inbound(int x, int y) {
        return x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1;
    }
    
    void DFS(int x, int y, string &s, TrieNode *r, vector<vector<char> > &b) {
        if (r == NULL) {
            return;
        }
        if (r->isWord) {
            // A word is found
            us.insert(s);
        }
        int x1, y1;
        int i;
        for (i = 0; i < 4; ++i) {
            x1 = x + d[i][0];
            y1 = y + d[i][1];
            if (!inbound(x1, y1) || v[x1][y1]) {
                continue;
            }
            v[x1][y1] = true;
            s.push_back(b[x1][y1]);
            DFS(x1, y1, s, r->child[b[x1][y1] - 'a'], b);
            s.pop_back();
            v[x1][y1] = false;
        }
    }
    
    void insertWord(TrieNode *root, string s) {
        int n = s.length();
        if (n == 0) {
            return;
        }
        int i;
        TrieNode *p = root;
        for (i = 0; i < n; ++i) {
            if (p->child[s[i] - 'a'] == NULL) {
                p->child[s[i] - 'a'] = new TrieNode();
            }
            p = p->child[s[i] - 'a'];
        }
        p->isWord = true;
    }
    
    void clearTrie(TrieNode *&root) {
        if (root == NULL) {
            return;
        }
        int i;
        for (i = 0; i < TrieNode::N; ++i) {
            clearTrie(root->child[i]);
        }
        root->child.clear();
        delete root;
        root = NULL;
    }
};