#include <unordered_map>
using namespace std;
/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int> > connectedSet(vector<UndirectedGraphNode*> &nodes) {
        int n = nodes.size();
        int i;
        
        dj.resize(n);
        for (i = 0; i < n; ++i) {
            dj[i] = i;
            um[nodes[i]] = i;
        }
        int j;
        int x, y, rx, ry;
        for (i = 0; i < n; ++i) {
            x = um[nodes[i]];
            for (j = 0; j < nodes[i]->neighbors.size(); ++j) {
                y = um[nodes[i]->neighbors[j]];
                rx = findRoot(x);
                ry = findRoot(y);
                dj[rx] = ry;
            }
        }
        vector<vector<int> > ans;
        unordered_map<int, vector<int> > cc;
        unordered_map<int, vector<int> >::iterator it;
        
        for (i = 0; i < n; ++i) {
            findRoot(i);
            cc[dj[i]].push_back(nodes[i]->label);
        }
        for (it = cc.begin(); it != cc.end(); ++it) {
            ans.push_back(it->second);
        }
        dj.clear();
        um.clear();
        cc.clear();
        
        return ans;
    }
private:
    vector<int> dj;
    unordered_map<UndirectedGraphNode*, int> um;
    
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