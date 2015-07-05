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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        unordered_set<ListNode *> us;
        ListNode *p = head;
        while (p != NULL) {
            if (us.find(p) != us.end()) {
                return true;
            }
            us.insert(p);
            p = p->next;
        }
        return false;
    }
};