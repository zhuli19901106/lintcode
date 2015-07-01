class Solution {
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        ans = 0;
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
    int ans;
    vector<bool> c, d, ad;
    int n;
    
    void DFS(int idx) {
        if (idx == n) {
            ++ans;
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
            
            c[i] = true;
            d[idx + i] = true;
            ad[n - 1 + idx - i] = true;
            
            DFS(idx + 1);
            
            ad[n - 1 + idx - i] = false;
            d[idx + i] = false;
            c[i] = false;
        }
    }
};