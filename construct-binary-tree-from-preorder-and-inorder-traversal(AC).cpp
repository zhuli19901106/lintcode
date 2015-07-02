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
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        if (n == 0) {
            return NULL;
        }
        return construct(preorder, inorder, 0, n - 1, 0, n - 1);
    }
private:
    TreeNode *construct(vector<int> &pre, vector<int> &in, 
                        int pll, int prr, int ill, int irr) {
        int rootVal = pre[pll];
        TreeNode *r = new TreeNode(rootVal);
        int i;
        for (i = ill; i <= irr; ++i) {
            if (in[i] == rootVal) {
                break;
            }
        }
        int len;
        if (i > ill) {
            len = i - ill;
            r->left = construct(pre, in, pll + 1, pll + len, ill, i - 1);
        }
        if (i < irr) {
            len = irr - i;
            r->right = construct(pre, in, prr - len + 1, prr, i + 1, irr);
        }
        return r;
    }
};