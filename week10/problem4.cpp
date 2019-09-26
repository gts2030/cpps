// O(M*N) / O(MxN)
#include <cmath>

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> sum(m * n, 0);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i != 0 && j != 0) {
                    sum[i*n + j] = std::min(sum[i*n + j-1], sum[(i-1)*n + j]) + grid[i][j];
                } else if(i == 0 && j == 0) {
                    sum[i*n + j] = grid[0][0];
                } else if(i == 0) {
                    sum[i*n + j] = sum[i*n + j-1] + grid[i][j];
                } else {
                    sum[i*n + j] = sum[(i-1)*n + j] + grid[i][j];
                }
            }
        }
        return sum[m*n-1];
    }
};
