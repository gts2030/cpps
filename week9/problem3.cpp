// O(1) / O(1)
#include <cmath>
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long int result = (long long int)dividend / divisor;
        if(result < -pow(2, 31) || result > pow(2, 31) - 1) return pow(2, 31) - 1;
        else return result;
    }
};
