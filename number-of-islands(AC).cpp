class Solution {
public:
    Solution() {
        d.resize(4, vector<int>(2));
        int i;
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
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool> > &grid) {
        n = grid.size();
        if (n == 0) {
            return 0;
        }
        m = grid[0].size();
        if (m == 0) {
            return 0;
        }
        int ans = 0;
        int i, j;
        
        b.resize(n, vector<bool>(m));
        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                if (grid[i][j] && !b[i][j]) {
                    ++ans;
                    DFS(i, j);
                }
            }
        }
        b.clear();
        return ans;
    }
private:
    vector<vector<bool> > b;
    vector<vector<int> > d;
    int n, m;
    
    void DFS(int x, int y, vector<vector<bool> > &grid) {
        b[x][y] = true;
        int x1, y1;
        int i;
        for (i = 0; i < 4; ++i) {
            x1 = x + d[i][0];
            y1 = y + d[i][1];
            if (x1 < 0 || x1 > n - 1 || y1 < 0 || y1 > m - 1) {
                continue;
            }
            if (grid[x1][y1] && !b[x1][y1]) {
                DFS(x1, y1, grid);
            }
        }
    }
};