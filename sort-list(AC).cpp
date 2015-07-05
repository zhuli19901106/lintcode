// Let's make it strictly O(1) in space
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
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        if (head == NULL) {
            return head;
        }
        
        int tlen = 0;
        ListNode *p1, *p2;
        
        p1 = head;
        while (p1 != NULL) {
            p1 = p1->next;
            ++tlen;
        }
        
        ListNode *h1, *t1;
        ListNode *h2, *t2;
        ListNode *h3, *t3;
        ListNode *h, *t;
        int len = 1;
        int i;
        while (len < tlen) {
            // Set all pointers to NULL
            h = t = NULL;
            while (true) {
                h1 = h2 = t1 = t2 = NULL;
                i = 0;
                // Get two sublists
                while (head != NULL && i < len) {
                    if (h1 == NULL) {
                        h1 = t1 = head;
                        head = head->next;
                    } else {
                        t1->next = head;
                        head = head->next;
                        t1 = t1->next;
                    }
                    t1->next = NULL;
                    ++i;
                }
                i = 0;
                while (head != NULL && i < len) {
                    if (h2 == NULL) {
                        h2 = t2 = head;
                        head = head->next;
                    } else {
                        t2->next = head;
                        head = head->next;
                        t2 = t2->next;
                    }
                    t2->next = NULL;
                    ++i;
                }
                if (h1 == NULL && h2 == NULL) {
                    break;
                }
                
                // Merge them into one sorted list
                p1 = h1;
                p2 = h2;
                h3 = t3 = NULL;
                while (p1 != NULL && p2 != NULL) {
                    if (p1->val < p2->val) {
                        if (h3 == NULL) {
                            h3 = t3 = p1;
                            p1 = p1->next;
                        } else {
                            t3->next = p1;
                            p1 = p1->next;
                            t3 = t3->next;
                        }
                    } else {
                        if (h3 == NULL) {
                            h3 = t3 = p2;
                            p2 = p2->next;
                        } else {
                            t3->next = p2;
                            p2 = p2->next;
                            t3 = t3->next;
                        }
                    }
                    t3->next = NULL;
                }
                while (p1 != NULL) {
                    if (h3 == NULL) {
                        h3 = t3 = p1;
                        p1 = p1->next;
                    } else {
                        t3->next = p1;
                        p1 = p1->next;
                        t3 = t3->next;
                    }
                    t3->next = NULL;
                }
                while (p2 != NULL) {
                    if (h3 == NULL) {
                        h3 = t3 = p2;
                        p2 = p2->next;
                    } else {
                        t3->next = p2;
                        p2 = p2->next;
                        t3 = t3->next;
                    }
                    t3->next = NULL;
                }
                
                // Add the list to tail
                if (h == NULL) {
                    h = h3;
                    t = t3;
                } else {
                    t->next = h3;
                    t = t3;
                }
            }
            head = h;
            len <<= 1;
        }
        return head;
    }
};