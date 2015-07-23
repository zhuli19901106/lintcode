#include <algorithm>
#include <climits>
using namespace std;
/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
typedef SegmentTreeNode STN;
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(STN *root, int start, int end) {
        if (start > end) {
            return INT_MIN;
        }
        if (start == root->start && end == root->end) {
            return root->max;
        }
        int mid = root->start + (root->end - root->start >> 1);
        int ans = INT_MIN;
        ans = max(ans, query(root->left, start, min(end, mid)));
        ans = max(ans, query(root->right, max(start, mid + 1), end));
        return ans;
    }
};