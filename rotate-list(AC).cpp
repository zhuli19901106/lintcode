/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) {
            return head;
        }
        
        int len = 1;
        ListNode *p = head;
        while (p->next != NULL) {
            p = p->next;
            ++len;
        }
        ListNode *t = p;
        
        k = (len - k % len) % len;
        if (k == 0) {
            return head;
        }
        
        p = head;
        int i;
        for (i = 0; i < k - 1; ++i) {
            p = p->next;
        }
        ListNode *h = p->next;
        p->next = NULL;
        t->next = head;
        return h;
    }
};