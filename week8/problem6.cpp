// O(N)/O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        return nums.size()*(nums.size() + 1)/2 - std::accumulate(nums.begin(), nums.end(), 0);
    }
};
