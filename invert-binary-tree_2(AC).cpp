#include <algorithm>
#include <queue>
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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
		// The iterative version.
		if (root == NULL) {
			return;
		}
		TreeNode *p;
		queue<TreeNode *> q;
		
		q.push(root);
		while (!q.empty()) {
			p = q.front();
			q.pop();
			swap(p->left, p->right);
			if (p->left != NULL) {
				q.push(p->left);
			}
			if (p->right != NULL) {
				q.push(p->right);
			}
		}
    }
};