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
     * @param head a ListNode
     * @return a ListNode
     */
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode *newHead = head->next;
        ListNode *p1, *p2, *p3;
        
        p1 = head;
        while (p1 != NULL && p1->next != NULL) {
            p2 = p1->next;
            p3 = p2->next;
            p2->next = p1;
            p1->next = p3 != NULL && p3->next != NULL ? p3->next : p3;
            p1 = p3;
        }
        
        return newHead;
    }
};
