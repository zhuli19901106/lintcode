/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
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
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        
        ListNode *p;
        int len = 0;
        p = head;
        while (p != NULL) {
            p = p->next;
            ++len;
        }
        return convert(head, len);
    }
private:
    TreeNode *convert(ListNode *head, int len) {
        if (len == 0) {
            return NULL;
        }
        if (len == 1) {
            return new TreeNode(head->val);
        }
        if (len == 2) {
            TreeNode *h = new TreeNode(head->val);
            h->right = new TreeNode(head->next->val);
            return h;
        }
        int i;
        ListNode *p = head;
        for (i = 1; i <= (len - 1) / 2; ++i) {
            p = p->next;
        }
        TreeNode *r = new TreeNode(p->val);
        r->left = convert(head, (len - 1) / 2);
        r->right = convert(p->next, len / 2);
        return r;
    }
};