// O(n ^ 2) solution
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
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DGN *> topSort(vector<DGN *> graph) {
        unordered_map<DGN *, int> ind;
        vector<DGN *> ans;
        int n, m;
        int i, j;
        
        n = graph.size();
        for (i = 0; i < n; ++i) {
            m = graph[i]->neighbors.size();
            for (j = 0; j < m; ++j) {
                ++ind[graph[i]->neighbors[j]];
            }
        }
        int cc;
        vector<bool> v(n, false);
        while (true) {
            cc = 0;
            for (i = 0; i < n; ++i) {
                if (v[i] || ind[graph[i]] != 0) {
                    continue;
                }
                ++cc;
                v[i] = true;
                ans.push_back(graph[i]);
                m = graph[i]->neighbors.size();
                for (j = 0; j < m; ++j) {
                    --ind[graph[i]->neighbors[j]];
                }
            }
            if (cc == 0) {
                break;
            }
        }
        return ans;
    }
};