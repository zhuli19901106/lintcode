// The running pointers
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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *p1, *p2;
        
        p1 = head;
        p2 = head->next;
        while (p2 != NULL) {
            p1 = p1->next;
            p2 = p2->next;
            if (p2 == NULL) {
                return false;
            }
            p2 = p2->next;
            if (p1 == p2) {
                return true;
            }
        }
        return false;
    }
};