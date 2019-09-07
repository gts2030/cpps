#include <limits>
class Solution {
    public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        for (int i = 1; i <= n; i++) {
            int min= std::numeric_limits<int>::max();
            for (int j = 1; j * j <= i; j++) {
                min= std::min(min, dp[i - j * j] + 1);
            }
            dp[i] = min;
        }
        return dp[n];
    }
};
