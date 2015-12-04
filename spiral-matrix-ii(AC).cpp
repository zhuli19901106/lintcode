class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int> > generateMatrix(int n) {
        const int d[4][2] = {
            {0, +1}, {+1, 0}, {0, -1}, {-1, 0}
        };
        
        vector<vector<int> > a;
        if (n <= 0) {
            return a;
        }
        this->n = n;
        a.resize(n, vector<int>(n, 0));
        
        int dir = 0;
        int cc = 0;
        int x, y;
        int x1, y1;
        int i;
        
        x = y = 0;
        while (true) {
            a[x][y] = ++cc;
            if (cc == n * n) {
                break;
            }
            for (i = 0; i < 4; ++i) {
                x1 = x + d[dir][0];
                y1 = y + d[dir][1];
                if (inbound(x1, y1) && a[x1][y1] == 0) {
                    x = x1;
                    y = y1;
                    break;
                }
                dir = (dir + 1) % 4;
            }
        }
        return a;
    }
protected:
    int n;
    
    bool inbound(int x, int y) {
        return x >= 0 && x <= n - 1 && y >= 0 && y <= n - 1;
    }
};
