#include <cmath>
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> prevs;
        int result;
        while(1) {
            result = 0;
            while(n) {
                result += pow(n%10, 2);
                n /= 10;
            }
            if(result == 1) return true;
            else if(prevs.find(result) != prevs.end()) return false;
            else {
                prevs.insert(result);
                n = result;
            }
        }
    }
};
