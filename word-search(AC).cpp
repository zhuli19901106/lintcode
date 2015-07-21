class Solution {
public:
    Solution() {
        d.resize(4, vector<int>(2));
        d[0][0] = -1;
        d[0][1] = 0;
        d[1][0] = +1;
        d[1][1] = 0;
        d[2][0] = 0;
        d[2][1] = -1;
        d[3][0] = 0;
        d[3][1] = +1;
    }
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        n = board.size();
        if (n == 0) {
            return false;
        }
        m = board[0].size();
        if (m == 0) {
            return false;
        }
        target = word;
        if (target == "") {
            return true;
        }
        b.clear();
        b.resize(n, vector<int>(m, false));
        ans = false;
        
        int i, j;
        for (i = 0; !ans && i < n; ++i) {
            for (j = 0; !ans && j < m; ++j) {
                if (board[i][j] != target[0]) {
                    continue;
                }
                b[i][j] = true;
                DFS(i, j, board, 1);
                b[i][j] = false;
            }
        }
        return ans;
    }
private:
    int n, m;
    string target;
    vector<vector<int> > b;
    vector<vector<int> > d;
    bool ans;
    
    bool inbound(int x, int y) {
        return x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1;
    }
    
    void DFS(int x, int y, vector<vector<char> > &board, int len) {
        if (ans) {
            return;
        }
        if (len == target.length()) {
            ans = true;
            return;
        }
        int i;
        int xx, yy;
        for (i = 0; i < 4; ++i) {
            xx = x + d[i][0];
            yy = y + d[i][1];
            if (!inbound(xx, yy)) {
                continue;
            }
            if (b[xx][yy]) {
                continue;
            }
            if (board[xx][yy] != target[len]) {
                continue;
            }
            b[xx][yy] = true;
            DFS(xx, yy, board, len + 1);
            b[xx][yy] = false;
        }
    }
};