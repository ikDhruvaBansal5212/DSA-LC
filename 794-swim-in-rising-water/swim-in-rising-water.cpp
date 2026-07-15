class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        // Min-heap: {maximum elevation so far, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        vector<pair<int, int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int time = curr[0];
            int row = curr[1];
            int col = curr[2];

            // Reached destination
            if (row == n - 1 && col == n - 1)
                return time;

            // Explore all 4 directions
            for (auto &dir : directions) {
                int newRow = row + dir.first;
                int newCol = col + dir.second;

                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < n &&
                    !visited[newRow][newCol]) {

                    visited[newRow][newCol] = true;
                    pq.push({max(time, grid[newRow][newCol]), newRow, newCol});
                }
            }
        }

        return -1;
    }
};