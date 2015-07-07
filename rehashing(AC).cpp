// This problem is a bit unreasonable.
// Why must the nodes be appended to the end of the list?
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
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        int n1 = hashTable.size();
        int n2 = n1 * 2;
        vector<ListNode *> ans(n2, NULL);
        vector<ListNode *> tail(n2, NULL);
        
        int i, j;
        ListNode *p, *q;
        for (i = 0; i < n1; ++i) {
            p = hashTable[i];
            while (p != NULL) {
                q = p->next;
                j = addr(p->val, n2);
                
                if (ans[j] == NULL) {
                    ans[j] = tail[j] = p;
                } else {
                    tail[j]->next = p;
                    tail[j] = p;
                }
                tail[j]->next = NULL;
                
                p = q;
            }
            hashTable[i] = NULL;
        }
        return ans;
    }
private:
    int addr(int val, int cap) {
        return val >= 0 ? val % cap : (val % cap + cap) % cap;
    }
};