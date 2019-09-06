class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> arr(n, true);
        
        for(int i = 2; i < sqrt(n); i++) {
            if(arr[i]) {
                for(int j = i+i; j < n; j += i) arr[j] = false;
            }
        }
        return count(arr.begin(), arr.end(), true) - 2;
    }
};
