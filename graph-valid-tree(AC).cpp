class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int> > &edges) {
        if (n < 0) {
            return false;
        }
        if (edges.size() != n - 1) {
            return false;
        }
        vector<int> dj;
        int x, y;
        int rx, ry;
        
        dj.resize(n);
        int i;
        for (i = 0; i < n; ++i) {
            dj[i] = i;
        }
        for (i = 0; i < n - 1; ++i) {
            x = edges[i][0];
            y = edges[i][1];
            rx = findRoot(dj, x);
            ry = findRoot(dj, y);
            if (rx == ry) {
                return false;
            } else {
                dj[rx] = ry;
            }
        }
        return true;
    }
protected:
    int findRoot(vector<int> &dj, int x) {
        int r = x;
        while (r != dj[r]) {
            r = dj[r];
        }
        int k = x;
        while (k != r) {
            x = dj[x];
            dj[k] = r;
            k = x;
        }
        return r;
    }
};
