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
	ListNode* partition(ListNode* head, int x) {
		ListNode* dummy = new ListNode(0);
		ListNode* ins = NULL;
		ListNode* tmp;

		dummy->next = head;
		ListNode* pt = dummy;
		while (pt->next) {
			if (pt->next->val >= x) {
				ins = pt;
				break;
			}
			pt = pt->next;
		}

		while (pt->next) {
			if (pt->next->val < x) {
				tmp = pt->next;
				pt->next = tmp->next;
				tmp->next = ins->next;
				ins->next = tmp;
				ins = tmp;
			}
			else if (pt->next) pt = pt->next;
		}
		return dummy->next;
	}
};