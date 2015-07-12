// O(n) time and O(n) space
#include <unordered_set>
using namespace std;
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
        unordered_set<ListNode *> us;
        ListNode *p = head;
        while (p != NULL) {
            if (us.find(p) != us.end()) {
                break;
            }
            us.insert(p);
            p = p->next;
        }
        return p;
    }
};