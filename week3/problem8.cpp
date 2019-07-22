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
	bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL) return false;
		ListNode* pt1 = head;
		ListNode* pt2 = head;

		while (pt2->next && pt2->next->next) {
			pt1 = pt1->next;
			pt2 = pt2->next->next;
			if (pt1->val == pt2->val) return true;
		}
		return false;
	}
};