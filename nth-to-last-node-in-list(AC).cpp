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
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode *nthToLast(ListNode *head, int n) {
        ListNode *p1, *p2;
        
        p1 = head;
        int i;
        for (i = 0; i < n; ++i) {
            p1 = p1->next;
        }
        p2 = head;
        while (p1 != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};