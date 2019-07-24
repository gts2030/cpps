class MinStack {
public:
	class stnode {
	public:
		stnode(int x) {
			val = x;
			next = NULL;
		}
		int val;
		stnode* next;
	};
	stnode* head;
	stnode* minhead;
	/** initialize your data structure here. */
	MinStack() {
		head = new stnode(0);
		minhead = new stnode(0);
	}

	~MinStack() {
		stnode* tmp;
		while (minhead->next) {
			tmp = minhead->next;
			minhead->next = tmp->next;
			delete tmp;
		}
		while (head->next) {
			tmp = head->next;
			head->next = tmp->next;
			delete tmp;
		}
		delete head;
		delete minhead;
	}

	void push(int x) {
		if (minhead->next) {
			if (minhead->next->val >= x) {
				stnode* tmp = new stnode(x);
				tmp->next = minhead->next;
				minhead->next = tmp;
			}
		}
		else {
			stnode* tmp = new stnode(x);
			tmp->next = minhead->next;
			minhead->next = tmp;
		}
		stnode* tmp = new stnode(x);
		tmp->next = head->next;
		head->next = tmp;
	}

	void pop() {
		stnode* tmp;
		if (minhead->next) {
			if (head->next->val == minhead->next->val) {
				tmp = minhead->next;
				minhead->next = tmp->next;
				delete tmp;
			}
		}
		if (head->next) {
			tmp = head->next;
			head->next = tmp->next;
			delete tmp;
		}
	}

	int top() {
		if (head->next) return head->next->val;
		else return NULL;
	}

	int getMin() {
		if (minhead->next) return minhead->next->val;
		else return NULL;
	}
};