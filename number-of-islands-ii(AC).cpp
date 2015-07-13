/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
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
     * @param n an integer
     * @param m an integer
     * @param operators an array of point
     * @return an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        b.clear();
        dj.clear();
        
        this->n = n;
        this->m = m;
        b.resize(n * m, false);
        dj.resize(n * m);
        
        int i;
        for (i = 0; i < n * m; ++i) {
            dj[i] = i;
        }
        
        int cc = 0;
        int x, y;
        int x1, y1;
        int r, r1;
        vector<int> ans;
        vector<int> adj;
        int j;
        for (i = 0; i < operators.size(); ++i) {
            x = operators[i].x;
            y = operators[i].y;
            if (b[x * m + y]) {
                ans.push_back(cc);
                continue;
            }
            b[x * m + y] = true;
            adj.clear();
            for (j = 0; j < 4; ++j) {
                x1 = x + d[j][0];
                y1 = y + d[j][1];
                if (inbound(x1, y1) && b[x1 * m + y1]) {
                    adj.push_back(x1 * m + y1);
                }
            }
            if (adj.empty()) {
                ans.push_back(++cc);
                continue;
            }
            dj[findRoot(adj[0])] = findRoot(x * m + y);
            for (j = 1; j < adj.size(); ++j) {
                r = findRoot(x * m + y);
                r1 = findRoot(adj[j]);
                if (r != r1) {
                    dj[r1] = r;
                    --cc;
                }
            }
            ans.push_back(cc);
        }
        return ans;
    }
private:
    vector<vector<int> > d;
    vector<int> b, dj;
    int n, m;
    
    bool inbound(int x, int y) {
        return x >=0 && x <= n - 1 && y >= 0 && y <= m - 1;
    }
    
    int findRoot(int x) {
        int r = x;
        while (r != dj[r]) {
            r = dj[r];
        }
        int k = x;
        while (x != r) {
            x = dj[x];
            dj[k] = r;
            k = x;
        }
        return r;
    }
};