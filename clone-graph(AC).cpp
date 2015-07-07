// Mapping and recursion
#include <unordered_map>
using namespace std;
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
typedef UndirectedGraphNode UGN;
class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UGN *cloneGraph(UGN *node) {
        if (node == NULL) {
            return NULL;
        }
        
        n = 0;
        um.clear();
        b.clear();
        v.clear();
        
        um[node] = n++;
        v.push_back(new UGN(node->label));
        b.push_back(false);
        DFS(node);
        
        return v[0];
    }
private:
    int n;
    unordered_map<UGN *, int> um;
    vector<bool> b;
    vector<UGN *> v;
    
    void DFS(UGN *node) {
        if (b[um[node]]) {
            return;            
        }
        b[um[node]] = true;
        UGN *newNode = v[um[node]];
        
        int nn = node->neighbors.size();
        int i;
        UGN *p;
        for (i = 0; i < nn; ++i) {
            p = node->neighbors[i];
            if (um.find(p) == um.end()) {
                um[p] = n++;
                b.push_back(false);
                v.push_back(new UGN(p->label));
            }
            newNode->neighbors.push_back(v[um[p]]);
        }
        for (i = 0; i < nn; ++i) {
            p = node->neighbors[i];
            DFS(p);
        }
    }
};