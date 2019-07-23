// Brute force O(n^2)
class Solution {
public:
	int trap(vector<int>& height) {
		std::vector<int> chk;
		int cnt = 0;
		for (int &num : height) {
			while (chk.size() < num) {
				chk.push_back(0);
			}
			for (int i = 0; i < chk.size(); i++) {
				if (i < num) {
					cnt += chk[i];
					chk[i] = 0;
				}
				else {
					chk[i]++;
				}
			}
		}
		return cnt;
	}
};