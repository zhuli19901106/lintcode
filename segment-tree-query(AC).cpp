#include <algorithm>
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
        if (root->start == root->end) {
            return root->max;
        }
        int mid = root->start + (root->end - root->start) / 2;
        if (end <= mid) {
            return query(root->left, start, end);
        }
        if (mid + 1 <= start) {
            return query(root->right, start, end);
        }
        int m1, m2;
        if (start == root->start) {
            m1 = root->left->max;
        } else {
            m1 = query(root->left, start, mid);
        }
        if (end == root->end) {
            m2 = root->right->max;
        } else {
            m2 = query(root->right, mid + 1, end);
        }
        return max(m1, m2);
    }
};