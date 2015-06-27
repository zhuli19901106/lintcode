/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
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
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *h = head;
        head = head->next;
        h->next = NULL;
        
        ListNode *p;
        while (head != NULL) {
            p = head;
            head = head->next;
            p->next = h;
            h = p;
        }
        return h;
    }
};