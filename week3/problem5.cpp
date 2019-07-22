/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <cmath>

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* pt1 = l1;
		ListNode* pt2 = l2;
		int n1 = 0, n2 = 0;
		while (pt1) {
			n1++;
			pt1 = pt1->next;
		}
		while (pt2) {
			n2++;
			pt2 = pt2->next;
		}
		if (n1 >= n2) {
			pt1 = l1;
			pt2 = l2;
		}
		else {
			pt1 = l2;
			pt2 = l1;
		}

		bool over = false;
		ListNode* prev;
		while (pt2) {
			if (over) {
				pt1->val++;
				over = false;
			}
			pt1->val += pt2->val;
			if (pt1->val > 9) {
				pt1->val %= 10;
				over = true;
			}
			prev = pt1;
			pt1 = pt1->next;
			pt2 = pt2->next;
		}
		if (over) {
			if (pt1 == NULL) prev->next = new ListNode(1);
			else {
				pt1->val++;
				while (pt1) {
					if (pt1->val > 9) {
						pt1->val %= 10;
						if (pt1->next == NULL) {
							pt1->next = new ListNode(1);
							break;
						}
						else pt1->next->val++;
					}
					pt1 = pt1->next;
				}
			}
		}
		if (n1 >= n2) return l1;
		else return l2;
	}
};