// O(N) / O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int max = 0, cur = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < cur) cur = prices[i];
            if(prices[i] - cur > max) max = prices[i] - cur;
        }
        return max;
    }
};
