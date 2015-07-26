// O(n) solution with hashing
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
typedef RandomListNode RLN;
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RLN *copyRandomList(RLN *head) {
        if (head == NULL) {
            return head;
        }
        int n, i;
        RLN *p;
        unordered_map<RLN *, int> um;
        vector<RLN *> v;
        
        p = head;
        n = 0;
        while (p != NULL) {
            um[p] = n++;
            v.push_back(new RLN(p->label));
            p = p->next;
        }
        
        for (i = 0; i < n - 1; ++i) {
            v[i]->next = v[i + 1];
        }
        p = head;
        for (i = 0; i < n; ++i) {
            v[i]->random = p->random != NULL ? v[um[p->random]] : NULL;
            p = p->next;
        }
        
        return v[0];
    }
};