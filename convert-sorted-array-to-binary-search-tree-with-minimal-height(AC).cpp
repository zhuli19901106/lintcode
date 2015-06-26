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
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode* sortedArrayToBST(vector<int> &A) {
		if (A.empty()) {
			return NULL;
		}
		return convert(A, 0, A.size() - 1);
    }
private:
	TreeNode* convert(vector<int> &a, int ll, int rr) {
		int mm = (ll + rr) / 2;
		TreeNode* root = new TreeNode(a[mm]);
		if (ll < mm) {
			root->left = convert(a, ll, mm - 1);
		}
		if (rr > mm) {
			root->right = convert(a, mm + 1, rr);
		}
		return root;
	}
};