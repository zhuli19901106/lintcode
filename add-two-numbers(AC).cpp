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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
		if (l1 == NULL) {
			return l2;
		}
		if (l2 == NULL) {
			return l1;
		}
		
		ListNode *h;
		ListNode *t;
		int c;
		
		h = t = new ListNode(l1->val + l2->val);
		c = t->val / 10;
		t->val %= 10;
		l1 = l1->next;
		l2 = l2->next;
		
		while (l1 != NULL && l2 != NULL) {
			t->next = new ListNode(l1->val + l2->val + c);
			t = t->next;
			c = t->val / 10;
			t->val %= 10;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1 != NULL) {
			t->next = new ListNode(l1->val + c);
			t = t->next;
			c = t->val / 10;
			t->val %= 10;
			l1 = l1->next;
		}
		while (l2 != NULL) {
			t->next = new ListNode(l2->val + c);
			t = t->next;
			c = t->val / 10;
			t->val %= 10;
			l2 = l2->next;
		}
		if (c) {
			t->next = new ListNode(1);
		}
		return h;
    }
};