// O(N) / O(N)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int limit = nums.size() / 2;
        for (const auto &num: nums) {
            if (++cnt[num] > limit) return num;
        }
        return 0;
    }
};
