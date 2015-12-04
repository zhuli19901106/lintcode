#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<vector<int> > &a = matrix;
        n = a.size();
        m = n ? a[0].size() : 0;
        vector<int> ans;
        int cc = n * m;
        if (cc == 0) {
            return ans;
        }
        
        const int d[4][2] = {
            {0, +1}, {+1, 0}, {0, -1}, {-1, 0}
        };
        int dir = 0;
        vector<vector<bool> > b(n, vector<bool>(m, false));
        
        int x, y;
        int x1, y1;
        int i;
        
        x = 0;
        y = 0;
        while (true) {
            ans.push_back(a[x][y]);
            b[x][y] = true;
            --cc;
            if (cc == 0) {
                break;
            }
            for (i = 0; i < 4; ++i) {
                x1 = x + d[dir][0];
                y1 = y + d[dir][1];
                if (inbound(x1, y1) && !b[x1][y1]) {
                    x = x1;
                    y = y1;
                    break;
                } else {
                    dir = (dir + 1) % 4;
                }
            }
        }
    }
protected:
    int n, m;
    
    bool inbound(int x, int y) {
        return x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1;
    }
};
