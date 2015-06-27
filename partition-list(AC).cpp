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
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL) {
            return head;
        }
        ListNode *h1, *t1, *h2, *t2;
        ListNode *p;
        
        h1 = t1 = NULL;
        h2 = t2 = NULL;
        while (head != NULL) {
            p = head;
            head = head->next;
            if (p->val < x) {
                if (h1 == NULL) {
                    h1 = t1 = p;
                    t1->next = NULL;
                } else {
                    t1->next = p;
                    t1 = t1->next;
                    t1->next = NULL;
                }
            } else {
                if (h2 == NULL) {
                    h2 = t2 = p;
                    t2->next = NULL;
                } else {
                    t2->next = p;
                    t2 = t2->next;
                    t2->next = NULL;
                }
            }
        }
        if (t1 != NULL) {
            t1->next = h2;
            return h1;
        } else {
            return h2;
        }
    }
};