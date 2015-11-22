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
     * @param k an integer
     * @return a ListNode
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k < 2 || head == NULL) {
            return head;
        }
        
        ListNode *newHead = NULL, *newTail = NULL;
        ListNode *p1, *h;
        ListNode *sh, *st;
        int i;
        
        while (true) {
            p1 = head;
            for (i = 1; i < k && p1 != NULL; ++i) {
                p1 = p1->next;
            }
            if (p1 == NULL) {
                if (newHead == NULL) {
                    newHead = head;
                } else {
                    newTail->next = head;
                }
                return newHead;
            }
            h = head;
            head = p1->next;
            p1->next = NULL;
            
            reverseList(h, sh, st);
            if (newHead == NULL) {
                newHead = sh;
                newTail = st;
            } else {
                newTail->next = sh;
                newTail = st;
            }
        }
    }
protected:
    void reverseList(ListNode *head, ListNode *&newHead, ListNode *&newTail) {
        if (head == NULL || head->next == NULL) {
            newHead = newTail = head;
            return;
        }
        newHead = newTail = head;
        head = head->next;
        newTail->next = NULL;
        
        ListNode *p;
        while (head != NULL) {
            p = head;
            head = head->next;
            p->next = newHead;
            newHead = p;
        }
    }
};
