// O(N) / O(1)
#include <cmath>
class Solution {
public:
    int reverse(int x) {
        if(x < -pow(2, 31) + 1 || x > pow(2, 31) - 1) return 0;
        
        int sign = 1, result = 0;
        if(x < 0) sign = -1;
        x = abs(x);
        
        while(x > 0) {            
            if(result < -pow(2,31)/10 || result > (pow(2, 31) - 1)/10) return 0;
            result *= 10;
            result += x % 10;
            x /= 10;   
        }
        return result * sign;
    }
};
