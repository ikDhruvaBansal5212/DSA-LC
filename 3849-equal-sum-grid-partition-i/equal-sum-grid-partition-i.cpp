class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        unsigned long long totalSum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                totalSum += grid[i][j];
            }
        }

        if (totalSum % 2 != 0) return false;

        unsigned long long sum1 = 0;
        for (int i = 0; i < m - 1; i++) {  
            for (int j = 0; j < n; j++) {
                sum1 += grid[i][j];
            }
            unsigned long long sum2 = totalSum - sum1;
            if (sum1 == sum2) {
                return true;
            }
        }

         sum1 = 0;
        for (int i = 0; i < n - 1; i++) {  
            for (int j = 0; j < m; j++) {
                sum1 += grid[j][i];
            }
            unsigned long long sum2 = totalSum - sum1;
            if (sum1 == sum2) {
                return true;
            }
        }

        return false;
    }
};
