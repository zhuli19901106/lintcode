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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        ListNode *p1, *p2;
        
        p1 = head;
        while (p1 != NULL) {
            p2 = head;
            while (true) {
                if (p2 == p1->next) {
                    return p2;
                }
                if (p2 == p1) {
                    break;
                }
                if (p2 == NULL) {
                    return NULL;
                }
                p2 = p2->next;
            }
            p1 = p1->next;
        }
        return NULL;
    }
};