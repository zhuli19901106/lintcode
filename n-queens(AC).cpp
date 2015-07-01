class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string> > solveNQueens(int n) {
        ans.clear();
        if (n == 0) {
            return ans;
        }
        this->n = n;
        c.resize(n);
        d.resize(2 * n - 1);
        ad.resize(2 * n - 1);
        DFS(0);
        return ans;
    }
private:
    vector<vector<string> > ans;
    vector<bool> c, d, ad;
    int n;
    vector<string> s;
    vector<int> b;
    
    void DFS(int idx) {
        if (idx == n) {
            convertBoard();
            ans.push_back(s);
            return;
        }
        int i;
        for (i = 0; i < n; ++i) {
            if (c[i]) {
                continue;
            }
            if (d[idx + i] || ad[n - 1 + idx - i]) {
                continue;
            }
            
            b.push_back(i);
            c[i] = true;
            d[idx + i] = true;
            ad[n - 1 + idx - i] = true;
            
            DFS(idx + 1);
            
            ad[n - 1 + idx - i] = false;
            d[idx + i] = false;
            c[i] = false;
            b.pop_back();
        }
    }
    
    void convertBoard() {
        int i;
        string line;
        s.clear();
        line.resize(n, '.');
        for (i = 0; i < n; ++i) {
            line[b[i]] = 'Q';
            s.push_back(line);
            line[b[i]] = '.';
        }
    }
};