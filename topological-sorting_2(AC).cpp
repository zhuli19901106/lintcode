// Solution using BFS
#include <queue>
#include <unordered_set>
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
        queue<DGN *> q;
        unordered_set<DGN *> us;
        
        for (i = 0; i < n; ++i) {
            if (ind[graph[i]] == 0) {
                q.push(graph[i]);
            }
        }
        
        DGN *p;
        while (!q.empty()) {
            p = q.front();
            q.pop();
            if (us.find(p) != us.end()) {
                // Already visited
                continue;
            }
            if (ind[p] > 0) {
                // In-degree is not zero
                q.push(p);
                continue;
            }
            
            ans.push_back(p);
            us.insert(p);
            m = p->neighbors.size();
            for (i = 0; i < m; ++i) {
                --ind[p->neighbors[i]];
                q.push(p->neighbors[i]);
            }
        }
        return ans;
    }
};