/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
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
     *@return: The count number in the interval [start, end] 
     */
    int query(STN *root, int start, int end) {
        if (root == NULL) {
            return 0;
        }
        if (start > root->end || end < root->start || start > end) {
            return 0;
        }
        if (root->start == root->end) {
            return root->count;
        }
        int mid = root->start + (root->end - root->start) / 2;
        if (end <= mid) {
            return query(root->left, start, end);
        }
        if (start >= mid + 1) {
            return query(root->right, start, end);
        }
        int c1 = root->start == start ? root->left->count : 
                 query(root->left, start, mid);
        int c2 = root->end == end ? root->right->count : 
                 query(root->right, mid + 1, end);
        return c1 + c2;
    }
};