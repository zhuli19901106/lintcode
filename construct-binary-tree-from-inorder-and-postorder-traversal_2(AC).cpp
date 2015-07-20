// Make it faster with hashing.
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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        inPos.clear();
        int n = inorder.size();
        if (n == 0) {
            return NULL;
        }
        int i;
        for (i = 0; i < n; ++i) {
            inPos[inorder[i]] = i;
        }
        return construct(inorder, postorder, 0, n - 1, 0, n - 1);
    }
private:
    unordered_map<int, int> inPos;
    
    TreeNode *construct(vector<int> &in, vector<int> &post, 
                        int ill, int irr, int pll, int prr) {
        int rootVal = post[prr];
        TreeNode *r = new TreeNode(rootVal);
        int i = inPos[rootVal];
        int len;
        if (i > ill) {
            len = i - ill;
            r->left = construct(in, post, ill, i - 1, pll, pll + len - 1);
        }
        if (i < irr) {
            len = irr - i;
            r->right = construct(in, post, i + 1, irr, prr - len, prr - 1);
        }
        return r;
    }
};