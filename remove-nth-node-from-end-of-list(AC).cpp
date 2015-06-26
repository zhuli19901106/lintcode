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
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode *p1, *p2;
		
		int i;
		p1 = head;
		for (i = 0; p1 != NULL && i < n + 1; ++i) {
			p1 = p1->next;
		}
		if (i < n + 1) {
			if (head->next == NULL) {
				delete head;
				head = NULL;
			} else {
				p1 = head->next;
				head->val = p1->val;
				head->next = p1->next;
				delete p1;
			}
			return head;
		}
		p2 = head;
		while (p1 != NULL) {
			p1 = p1->next;
			p2 = p2->next;
		}
		p1 = p2->next;
		p2->next = p1->next;
		delete p1;
		return head;
    }
};