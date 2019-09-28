// O(coin*amount) / O(amount)
#include <limits>
class Solution {
public:
   int coinChange(vector<int>& coins, int amount) {
       if(amount == 0) return 0;
       vector<int> cnt(amount + 1, std::numeric_limits<int>::max());
       int min;
       for(int i = 1; i < amount + 1; i++) {
           for(const auto& coin : coins) {
               if(coin == i) cnt[coin] = 1;
               else if(coin < i && cnt[i-coin] != std::numeric_limits<int>::max())
                   cnt[i] = std::min(cnt[i-coin] + 1, cnt[i]);
           }
       }
       if(cnt[amount] != std::numeric_limits<int>::max()) return cnt[amount];
       else return -1;
   }
};
