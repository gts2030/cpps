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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode* pt = head;
		head = new ListNode(0);
		ListNode* tmp;
		ListNode* prev = NULL;

		while (pt != NULL && pt->next != NULL) {
			if (pt->val != pt->next->val) {
				prev = pt;
				pt = pt->next;
				if (head->next == NULL) head->next = prev;
				continue;
			}
			while (pt->val == pt->next->val) {
				tmp = pt;
				if (head->next != NULL) prev->next = pt->next;
				pt = pt->next;
				delete tmp;
				if (pt->next == NULL) {
					delete pt;
					if (head->next != NULL) prev->next = NULL;
					return head->next;
				}
			}
			tmp = pt;
			pt = pt->next;
			if (head->next == NULL) {
				if (pt->next == NULL) head->next = pt;
				else if (pt->val != pt->next->val) head->next = pt;
			}
			else if (prev != NULL) prev->next = pt;
			delete tmp;
		}
		return head->next;
	}
};