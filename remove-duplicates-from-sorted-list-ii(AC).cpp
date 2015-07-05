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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode *p = head, *q;
        ListNode *h = NULL;
        ListNode *t;
        int val;
        while (p != NULL) {
            if (p->next == NULL || p->val != p->next->val) {
                if (h == NULL) {
                    h = t = p;
                } else {
                    t->next = p;
                    t = t->next;
                }
                p = p->next;
                t->next = NULL;
                continue;
            }
            val = p->val;
            while (p != NULL && p->val == val) {
                q = p;
                p = p->next;
                delete q;
            }
        }
        return h;
    }
};