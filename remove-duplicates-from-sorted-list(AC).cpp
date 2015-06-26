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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) {
            return head;
        }
        ListNode *p = head;
        ListNode *q;
        while (p->next != NULL) {
            if (p->val == p->next->val) {
                q = p->next;
                p->next = q->next;
                delete q;
                continue;
            }
            p = p->next;
        }
        return head;
    }
};