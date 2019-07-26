/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* prev;
	Node* next;
	Node* child;

	Node() {}

	Node(int _val, Node* _prev, Node* _next, Node* _child) {
		val = _val;
		prev = _prev;
		next = _next;
		child = _child;
	}
};
*/
// O(N)/O(1)
class Solution {
public:
	Node* flatten(Node* head) {
		Node* pt = head;
		while (pt) {
			if (pt->child) {
				Node* tmp = pt->next;
				pt->next = pt->child;
				pt->child->prev = pt;
				pt->child = NULL;
				Node* runner = pt->next;
				while (runner->next) runner = runner->next;
				runner->next = tmp;
				if (tmp) tmp->prev = runner;
			}
			pt = pt->next;
		}
		return head;
	}
};