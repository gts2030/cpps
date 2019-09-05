// O(log(x)) / O(1)
#include <cmath>
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int tmp = x, len = 0;
        while(tmp) {
            tmp /= 10;
            len++;
        }
        while(len > 0) {
            if(x/(int)pow(10, len-1) != x % 10) return false;
            x = x % (int)pow(10, len-1);
            x /= 10;
            len -= 2;
        }
        return true;
    }
};
