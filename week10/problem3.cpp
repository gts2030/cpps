// O(N) / O(1)
#include <cmath>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev = nums[0];
        int max = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            if(prev >= 0) prev = prev + nums[i];
            else prev = nums[i];
            max = std::max(max, prev);
        }
        
        return max;
    }
};
