// This is my idea :)
#include <climits>
#include <vector>
using std::vector;
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
typedef long long int LL;
class Solution {
public:
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        if (T1 == NULL) {
            return T2 == NULL;
        }
        if (T2 == NULL) {
            return true;
        }
        pre1.clear();
        pre2.clear();
        in1.clear();
        in2.clear();
        
        preorder(T1, pre1);
        preorder(T2, pre2);
        inorder(T1, in1);
        inorder(T2, in2);
        
        return KMPMatch(pre1, pre2) && KMPMatch(in1, in2);
    }
private:
    vector<LL> pre1, in1, pre2, in2;
    vector<int> next;
    int ls, lt;
    
    void preorder(TreeNode *r, vector<LL> &v) {
        if (r == NULL) {
            v.push_back(LONG_LONG_MAX);
            return;
        }
        v.push_back(r->val);
        preorder(r->left, v);
        preorder(r->right, v);
    }
    
    void inorder(TreeNode *r, vector<LL> &v) {
        if (r == NULL) {
            v.push_back(LONG_LONG_MAX);
            return;
        }
        inorder(r->left, v);
        v.push_back(r->val);
        inorder(r->right, v);
    }
    
    void getNext(vector<LL> &t) {
        int i, j;
        i = 0;
        j = -1;
        
        next.clear();
        next.resize(lt + 1);
        next[0] = -1;
        while (i < lt) {
            if (j == -1 || t[i] == t[j]) {
                ++i;
                ++j;
                next[i] = j;
            } else {
                j = next[j];
            }
        }
    }
    
    bool KMPMatch(vector<LL> &s, vector<LL> &t) {
        ls = s.size();
        lt = t.size();
        getNext(t);
        
        int i, j;
        i = j = 0;
        while (i < ls) {
            if (j == -1 || s[i] == t[j]) {
                ++i;
                ++j;
            } else {
                j = next[j];
            }
            if (j == lt) {
                return true;
            }
        }
        return false;
    }
};