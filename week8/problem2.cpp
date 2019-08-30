// O(N)/O(N)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> s;
        for(const auto &num : nums) s.insert(num);
        int sum = std::accumulate(s.begin(), s.end(), 0);
        int sum_vec = std::accumulate(nums.begin(), nums.end(), 0);
        return sum*2 - sum_vec;
    }
};
