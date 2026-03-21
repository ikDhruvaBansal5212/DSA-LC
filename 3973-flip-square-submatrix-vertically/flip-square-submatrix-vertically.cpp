class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        // 🔒 Prevent crash on empty input
        if (grid.empty() || grid[0].empty()) return grid;

        int m = grid.size();
        int n = grid[0].size();

        int m0 = x + k-1;
        int n0 = y + k-1;

        while (x < m0) {
            for (int i = y; i <= n0; i++) {
                swap(grid[x][i], grid[m0][i]);
            }
            x++;
            m0--;
        }

        return grid;
    }
};