// Whimsical solution
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) {
            return head;
        }
        
        RandomListNode *p, *q;
        RandomListNode *h;
        
        p = head;
        while (p != NULL) {
            q = p->random;
            p->random = new RandomListNode(p->label);
            p->random->next = q;
            
            p = p->next;
        }
        
        p = head;
        while (p != NULL) {
            q = p->random;
            q->random = q->next ? q->next->random : NULL;
            
            p = p->next;
        }
        h = head->random;
        p = head;
        while (p != NULL) {
            q = p->random;
            p->random = q->next;
            q->next = p->next ? p->next->random : NULL;
            
            p = p->next;
        }
        return h;
    }
};