#include <stack>
class MyQueue {
public:
	std::stack<int> front;
	std::stack<int> back;
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		back.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (front.size() == 0) {
			while (back.size()) {
				front.push(back.top());
				back.pop();
			}
		}
		int result = front.top();
		front.pop();
		return result;
	}

	/** Get the front element. */
	int peek() {
		if (front.size() == 0) {
			while (back.size()) {
				front.push(back.top());
				back.pop();
			}
		}
		return front.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		if (front.size() + back.size() > 0) return false;
		else return true;
	}
};