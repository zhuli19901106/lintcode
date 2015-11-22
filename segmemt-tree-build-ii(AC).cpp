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
class Solution {
public:
    /**
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode *build(vector<int> &A) {
        return !A.empty() ? buildRecursive(A, 0, A.size() - 1) : NULL;
    }
protected:
    SegmentTreeNode *buildRecursive(vector<int> &a, int start, int end) {
        SegmentTreeNode *root = NULL;
        if (start == end) {
            root = new SegmentTreeNode(start, end, a[start]);
        } else {
            int mid = start + (end - start) / 2;
            SegmentTreeNode *left = buildRecursive(a, start, mid);
            SegmentTreeNode *right = buildRecursive(a, mid + 1, end);
            root = new SegmentTreeNode(start, end, max(left->max, right->max));
            root->left = left;
            root->right = right;
        }
        
        return root;
    }
};
