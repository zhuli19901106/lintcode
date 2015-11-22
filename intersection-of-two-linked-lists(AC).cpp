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
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la, lb;
        ListNode *pa, *pb;
        
        la = countLength(headA);
        lb = countLength(headB);
        pa = headA;
        pb = headB;
        if (la < lb) {
            moveForward(pb, lb - la);
        } else {
            moveForward(pa, la - lb);
        }
        while (pa != pb) {
            pa = pa->next;
            pb = pb->next;
        }
        return pa;
    }
protected:
    int countLength(ListNode *head) {
        int len = 0;
        ListNode *p = head;
        while (p != NULL) {
            p = p->next;
            ++len;
        }
        return len;
    }
    
    void moveForward(ListNode *&node, int count) {
        int i = 0;
        while (i < count && node != NULL) {
            node = node->next;
            ++i;
        }
    }
};
