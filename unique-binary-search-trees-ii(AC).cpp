#include <unordered_map>
using namespace std;
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) {
            // Special case
            vector<TreeNode *> v;
            v.push_back(NULL);
            return v;
        }
        
        int i;
        this->n = n;
        id.resize(n);
        for (i = 0; i < n; ++i) {
            id[i] = i + 1;
        }
        this->um.clear();
        constructTree(0, n - 1);
        return um[n - 1];
    }
private:
    unordered_map<int, vector<TreeNode *> > um;
    vector<int> id;
    int n;
    
    void constructTree(int ll, int rr) {
        if (um.find(ll * n + rr) != um.end()) {
            return;
        }
        vector<TreeNode *> v;
        if (ll == rr) {
            v.push_back(new TreeNode(id[ll]));
            um[ll * n + rr] = v;
            return;
        }
        
        int i;
        TreeNode *p;
        vector<TreeNode *> *pl, *pr;
        
        constructTree(ll + 1, rr);
        pl = &(um[(ll + 1) * n + rr]);
        for (i = 0; i < pl->size(); ++i) {
            p = new TreeNode(id[ll]);
            p->right = (*pl)[i];
            v.push_back(p);
        }
        
        constructTree(ll, rr - 1);
        pl = &(um[ll * n + rr - 1]);
        for (i = 0; i < pl->size(); ++i) {
            p = new TreeNode(id[rr]);
            p->left = (*pl)[i];
            v.push_back(p);
        }
        
        int j, k;
        for (i = ll + 1; i < rr; ++i) {
            constructTree(ll, i - 1);
            constructTree(i + 1, rr);
            pl = &(um[ll * n + i - 1]);
            pr = &(um[(i + 1) * n + rr]);
            for (j = 0; j < pl->size(); ++j) {
                for (k = 0; k < pr->size(); ++k) {
                    p = new TreeNode(id[i]);
                    p->left = (*pl)[j];
                    p->right = (*pr)[k];
                    v.push_back(p);
                }
            }
        }
        um[ll * n + rr] = v;
    }
};