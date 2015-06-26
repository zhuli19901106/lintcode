#include <algorithm>
#include <climits>
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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        if (root == NULL) {
			return 0;
		}
		if (root->left == NULL && root->right == NULL) {
			return 1;
		}
		int ans = INT_MAX;
		if (root->left != NULL) {
			ans = min(ans, minDepth(root->left) + 1);
		}
		if (root->right != NULL) {
			ans = min(ans, minDepth(root->right) + 1);
		}
		
		return ans;
    }
};