#include <vector>
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
    string serialize(TreeNode *root) {
        serializePreorder(root);
        
        string ans = "";
        int n = v.size();
        int i;
        for (i = 0; i < n; ++i) {
            ans += v[i];
            ans.push_back(' ');
        }
        ans.pop_back();
        v.clear();
        
        return ans;
    }

    TreeNode *deserialize(string data) {
        int n = data.length();
        int i, j;
        string s;
        
        while (i < n) {
            s = "";
            j = i;
            while (j < n && data[j] != ' ') {
                s.push_back(data[j++]);
            }
            v.push_back(s);
            ++j;
            i = j;
        }
        
        idx = 0;
        TreeNode *root;
        deserializePreorder(root);
        v.clear();
        
        return root;
    }
private:
    vector<string> v;
    int idx;
    
    void serializePreorder(TreeNode *root) {
        if (root == NULL) {
            v.push_back("#");
            return;
        }
        v.push_back(to_string(root->val));
        serializePreorder(root->left);
        serializePreorder(root->right);
    }
    
    void deserializePreorder(TreeNode *&root) {
        if (v[idx] == "#") {
            root = NULL;
            ++idx;
        } else {
            root = new TreeNode(atoi(v[idx].data()));
            ++idx;
            deserializePreorder(root->left);
            deserializePreorder(root->right);
        }
    }
};