#include <queue>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 1pass version
class Solution {
public:
	std::queue<ListNode*> tmp;
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL || head->next == NULL) return NULL;
		ListNode* pt = head;
		ListNode* dummy;
		int cnt = 0;
		while (pt) {
			tmp.push(pt);
			if (cnt > n) tmp.pop();
			cnt++;
			pt = pt->next;
		}

		if (cnt == n) {
			dummy = head;
			head = head->next;
		}
		else {
			dummy = tmp.front()->next;
			tmp.front()->next = dummy->next;
		}
		delete dummy;

		return head;
	}
};


// 2pass version
#include <queue>
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
	std::queue<ListNode*> tmp;
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		int length = 0;
		ListNode* pt = head;
		while (pt) {
			length++;
			pt = pt->next;
		}
		length -= n;
		pt = dummy;
		while (length > 0) {
			length--;
			pt = pt->next;
		}
		ListNode* tmp;
		tmp = pt->next;
		pt->next = tmp->next;
		delete tmp;
		return dummy->next;
	}
};