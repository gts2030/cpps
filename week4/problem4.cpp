#include <stack>
class Solution {
public:
	int calculate(string s) {
		std::stack<int> subres;
		int result = 0;
		int sign = 1;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') continue;
			else if (std::isdigit(s[i])) {
				int num = 0;
				while (std::isdigit(s[i]) && i < s.length()) {
					num *= 10;
					num += (s[i] - 48);
					i++;
				}
				i--;
				result += num * sign;
			}
			else if (s[i] == '+') {
				sign = 1;
			}
			else if (s[i] == '-') {
				sign = -1;
			}
			else if (s[i] == '(') {
				subres.push(result);
				subres.push(sign);
				result = 0;
				sign = 1;
			}
			else if (s[i] == ')') {
				sign = subres.top();
				subres.pop();
				result *= sign;
				result += subres.top();
				subres.pop();
			}
		}
		return result;
	}
};