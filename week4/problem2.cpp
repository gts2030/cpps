#include <queue>
#include <stack>
class Solution {
public:
	bool isValid(string s) {
		std::stack<char> open;
		char tmp;

		for (const auto &ch : s) {
			if (ch == '(' || ch == '{' || ch == '[') {
				open.push(ch);
				tmp = ch;
			}
			else {
				if (open.size() < 1) return false;
				switch (ch) {
				case ')':
					if (open.top() != '(') return false;
					open.pop();
					break;
				case '}':
					if (open.top() != '{') return false;
					open.pop();
					break;
				case ']':
					if (open.top() != '[') return false;
					open.pop();
					break;
				}
			}
		}
		if (open.size() > 0) return false;
		else return true;
	}
};