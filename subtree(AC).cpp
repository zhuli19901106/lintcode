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
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
		if (sameTree(T1, T2)) {
			return true;
		}
		if (T1 == NULL) {
			return false;
		}
		return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
    }
private:
	bool sameTree(TreeNode *r1, TreeNode *r2) {
		if (r1 == NULL) {
			if (r2 == NULL) {
				return true;
			}
			return false;
		}
		if (r2 == NULL) {
			return false;
		}
		if (r1->val != r2->val) {
			return false;
		}
		return sameTree(r1->left, r2->left) && sameTree(r1->right, r2->right);
	}
};