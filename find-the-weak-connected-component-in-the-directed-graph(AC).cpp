#include <algorithm>
#include <unordered_map>
using namespace std;
/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
typedef DirectedGraphNode DGN;
class Solution {
public:
    /**
     * @param nodes a array of directed graph node
     * @return a connected set of a directed graph
     */
    vector<vector<int> > connectedSet2(vector<DGN *> &nodes) {
        dj.clear();
        comp.clear();
        ans.clear();
        
        int n = nodes.size();
        int i, j;
        for (i = 0; i < n; ++i) {
            dj[nodes[i]] = nodes[i];
        }
        int m;
        DGN *x, *y, *rx, *ry;
        for (i = 0; i < n; ++i) {
            m = nodes[i]->neighbors.size();
            for (j = 0; j < m; ++j) {
                x = nodes[i];
                y = nodes[i]->neighbors[j];
                rx = findRoot(x);
                ry = findRoot(y);
                if (rx == ry) {
                    continue;
                }
                dj[rx] = ry;
            }
        }
        for (i = 0; i < n; ++i) {
            findRoot(nodes[i]);
            comp[dj[nodes[i]]].push_back(nodes[i]->label);
        }
        for (auto it = comp.begin(); it != comp.end(); ++it) {
            sort(it->second.begin(), it->second.end());
            ans.push_back(it->second);
        }
        return ans;
    }
private:
    unordered_map<DGN *, DGN *> dj;
    unordered_map<DGN *, vector<int> > comp;
    vector<vector<int> > ans;
    
    DGN *findRoot(DGN *x) {
        DGN *r = x;
        while (r != dj[r]) {
            r = dj[r];
        }
        DGN *k = x;
        while (x != r) {
            x = dj[x];
            dj[k] = r;
            k = x;
        }
        return r;
    }
};