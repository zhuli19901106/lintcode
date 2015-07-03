#include <algorithm>
#include <unordered_map>
#include <vector>
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
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        um.clear();
        dep.clear();
        v.clear();
        p.clear();
        
        if (root == NULL || A == NULL || B == NULL) {
            return NULL;
        }
        if (A == B) {
            return A;
        }
        
        maxd = n = 0;
        preorder(root, 1);
        p.resize(n, vector<int>(MAXDEP));
        getParents(root);
        
        int i, j;
        for (i = 1; i < MAXDEP; ++i) {
            for (j = 0; j < n; ++j) {
                p[j][i] = p[p[j][i - 1]][i - 1];
            }
        }
        
        return v[LCA(um[A], um[B])];
    }
private:
    static const int MAXDEP = 16;
    unordered_map<TreeNode *, int> um;
    vector<int> dep;
    vector<TreeNode *> v;
    vector<vector<int> > p;
    int n;
    int maxd;
    
    void preorder(TreeNode *root, int d) {
        maxd = max(maxd, d);
        
        um[root] = n++;
        v.push_back(root);
        dep.push_back(d);
        if (root->left != NULL) {
            preorder(root->left, d + 1);
        }
        if (root->right != NULL) {
            preorder(root->right, d + 1);
        }
    }
    
    void getParents(TreeNode *root) {
        if (root->left != NULL) {
            p[um[root->left]][0] = um[root];
            getParents(root->left);
        }
        if (root->right != NULL) {
            p[um[root->right]][0] = um[root];
            getParents(root->right);
        }
    }
    
    int LCA(int x, int y) {
        if (dep[x] < dep[y]) {
            return LCA(y, x);
        }
        
        int i;
        for (i = MAXDEP - 1; i >= 0; --i) {
            if (dep[p[x][i]] >= dep[y]) {
                x = p[x][i];
            }
            if (dep[x] == dep[y]) {
                break;
            }
        }
        if (x == y) {
            return x;
        }
        
        for (i = MAXDEP - 1; i >= 0; --i) {
            if (p[x][i] != p[y][i]) {
                x = p[x][i];
                y = p[y][i];
            }
        }
        return p[x][0];
    }
};