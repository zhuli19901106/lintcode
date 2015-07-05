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
     * @return: void
     */
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return;
        }
        
        ListNode *h1, *h2;
        ListNode *p1, *p2;
        
        p1 = p2 = head;
        h1 = head;
        while (true) {
            p2 = p2->next;
            if (p2 == NULL) {
                break;
            }
            p2 = p2->next;
            if (p2 == NULL) {
                break;
            }
            p1 = p1->next;
        }
        h2 = p1->next;
        p1->next = NULL;
        h2 = reverseList(h2);
        
        ListNode *h, *t;
        h = t = h1;
        h1 = h1->next;
        t->next = NULL;
        while (h1 != NULL && h2 != NULL) {
            t->next = h2;
            h2 = h2->next;
            t = t->next;
            t->next = NULL;
            
            t->next = h1;
            h1 = h1->next;
            t = t->next;
            t->next = NULL;
        }
        while (h1 != NULL) {
            t->next = h1;
            h1 = h1->next;
            t = t->next;
            t->next = NULL;
        }
        while (h2 != NULL) {
            t->next = h2;
            h2 = h2->next;
            t = t->next;
            t->next = NULL;
        }
    }
private:
    ListNode *reverseList(ListNode *head) {
        if (head == NULL) {
            return head;
        }
        ListNode *h, *p;
        
        h = head;
        head = head->next;
        h->next = NULL;
        while (head != NULL) {
            p = head->next;
            head->next = h;
            h = head;
            head = p;
        }
        return h;
    }
};