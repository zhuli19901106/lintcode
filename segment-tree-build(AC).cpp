/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
typedef SegmentTreeNode STN;
class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    STN *build(int start, int end) {
        if (start > end) {
            return NULL;
        }
        STN *root = new STN(start, end);
        if (start == end) {
            return root;
        }
        int mid = start + (end - start) / 2;
        root->left = build(start, mid);
        root->right = build(mid + 1, end);
        return root;
    }
};