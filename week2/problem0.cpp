class Solution {
public:
	int arrayNesting(vector<int>& nums) {
		bool* visited;
		visited = new bool[nums.size()];
		int result = 0;
		for (int i = 0; i < nums.size(); i++) visited[i] = false;
		for (int i = 0; i < nums.size(); i++) {
			if (!visited[i]) {
				int start = nums[i];
				int cnt = 0;
				do {
					start = nums[start];
					if (visited[start]) break;
					else {
						visited[start] = true;
						cnt++;
					}
				} while (start != nums[i]);
				if (cnt > result) result = cnt;
			}
		}
		return result;
	}
};