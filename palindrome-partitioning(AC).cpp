class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string> > partition(string s) {
        pal.clear();
        ans.clear();
        n = s.length();
        if (n == 0) {
            return ans;
        }
        
        pal.resize(n, vector<bool>(n, false));
        int i, j;
        for (i = 0; i < n; ++i) {
            pal[i][i] = true;
        }
        for (i = 0; i < n - 1; ++i) {
            pal[i][i + 1] = (s[i] == s[i + 1]);
        }
        for (i = 2; i < n; ++i) {
            for (j = 0; j + i < n; ++j) {
                pal[j][j + i] = (s[j] == s[j + i]) && pal[j + 1][j + i - 1];
            }
        }
        vector<string> par;
        DFS(s, par, 0);
        
        return ans;
    }
private:
    int n;
    vector<vector<bool> > pal;
    vector<vector<string> > ans;
    
    void DFS(string &s, vector<string> &par, int idx) {
        if (idx == n) {
            ans.push_back(par);
            return;
        }
        int i;
        for (i = n - 1; i >= idx; --i) {
            if (!pal[idx][i]) {
                continue;
            }
            par.push_back(s.substr(idx, i - idx + 1));
            DFS(s, par, i + 1);
            par.pop_back();
        }
    }
};