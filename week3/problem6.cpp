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
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL) return true;
		ListNode* pt, *pt2;
		pt = head;
		pt2 = head;
		while (pt2->next && pt2->next->next) {
			pt = pt->next;
			pt2 = pt2->next->next;
		}

		ListNode* dummy = new ListNode(0);
		dummy->next = pt->next;
		pt->next = NULL;

		pt = dummy->next;
		pt2 = pt->next;
		pt->next = NULL;
		while (pt2) {
			dummy->next = pt;
			pt = pt2;
			pt2 = pt2->next;
			pt->next = dummy->next;
		}

		while (head && pt) {
			if (head->val != pt->val) {
				delete dummy;
				return false;
			}
			head = head->next;
			pt = pt->next;
		}
		delete dummy;
		return true;
	}
};