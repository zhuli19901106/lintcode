/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == NULL) {
            return head;
        }
        int len = 0;
        ListNode *p = head;
        while (p != NULL) {
            p = p->next;
            ++len;
        }
        ListNode *t1, *h2, *h3;
        
        int i;
        if (m == 1) {
            t1 = NULL;
        } else {
            t1 = head;
            for (i = 2; i < m; ++i) {
                t1 = t1->next;
            }
        }
        
        p = head;
        for (i = 1; i < n; ++i) {
            p = p->next;
        }
        h3 = p->next;
        p->next = NULL;
        
        ListNode *t2;
        ListNode *tmp;
        
        p = t1 != NULL ? t1->next : head;
        h2 = t2 = p;
        p = p->next;
        t2->next = h3;
        while (p != NULL) {
            tmp = p->next;
            p->next = h2;
            h2 = p;
            p = tmp;
        }
        if (t1 != NULL) {
            t1->next = h2;
            return head;
        } else {
            return h2;
        }
    }
};