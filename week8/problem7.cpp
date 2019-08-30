// O(log(max(a,b)))/O(1)
class Solution {
public:
    int getSum(int a, int b) {
        // Iterate till there is no carry  
        while (b != 0) {
            int carry = a & b;  
            a = a ^ b;  
            b = carry << 1;  
        }
        return a;
    }
};
