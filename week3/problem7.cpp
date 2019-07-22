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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL) return NULL;
		ListNode* pt1 = headA;
		ListNode* pt2 = headB;
		int l1 = 0, l2 = 0;
		while (pt1->next) {
			pt1 = pt1->next;
			l1++;
		}
		while (pt2->next) {
			pt2 = pt2->next;
			l2++;
		}
		if (pt1 != pt2) return NULL;

		pt1 = headA;
		pt2 = headB;
		if (l1 >= l2) for (int i = 0; i < l1 - l2; i++) pt1 = pt1->next;
		else for (int i = 0; i < l2 - l1; i++) pt2 = pt2->next;
		while (pt1 && pt2) {
			if (pt1 == pt2) return pt1;
			pt1 = pt1->next;
			pt2 = pt2->next;
		}
		return NULL;
	}
};