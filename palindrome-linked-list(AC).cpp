// Too many bugs
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
     * @return a boolean
     */
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        
        ListNode *p1, *p2;
        p1 = p2 = head;
        while (p2->next != NULL && p2->next->next != NULL) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        ListNode *h1, *t1, *h2;
        
        h1 = head;
        t1 = p1;
        h2 = t1->next;
        t1->next = NULL;
        
        h2 = reverseList(h2);
        
        p1 = h1;
        p2 = h2;
        while (p2 != NULL) {
            if (p1->val != p2->val) {
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        bool isPal = p2 == NULL;
        h2 = reverseList(h2);
        t1->next = h2;
        
        return isPal;
    }
protected:
    ListNode *reverseList(ListNode *head) {
        if (head == NULL) {
            return head;
        }
        ListNode *newHead = head;
        head = head->next;
        newHead->next = NULL;
        
        ListNode *ptr = head;
        while (head != NULL) {
            ptr = head->next;
            head->next = newHead;
            newHead = head;
            head = ptr;
        }
        return newHead;
    }
};
