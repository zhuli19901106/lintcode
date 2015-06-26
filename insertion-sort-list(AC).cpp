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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
		if (head == NULL) {
			return NULL;
		}
		ListNode *h = NULL;
		ListNode *p;
		ListNode *q;
		
		h = head;
		head = head->next;
		h->next = NULL;
		while (head != NULL) {
			p = head;
			head = head->next;
			if (p->val <= h->val) {
				p->next = h;
				h = p;
				continue;
			}
			q = h;
			while (q->next != NULL && q->next->val < p->val) {
				q = q->next;
			}
			p->next = q->next;
			q->next = p;
		}
		return h;
    }
};