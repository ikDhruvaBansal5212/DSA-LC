class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};
        for (int row = 0; row < n ; row++) {
            for (int col = 0; col < n ; col++) {                
                if (grid[row][col] == 0) continue;                
                for (int ind = 0; ind < 4; ind++) {
                    int newRow = row + delRow[ind];
                    int newCol = col + delCol[ind];                    
                    if (newRow>=0 && newRow<n && newCol>=0 && newCol<n&& 
                        grid[newRow][newCol] == 1) {                            
                        int nodeNo = row * n + col;
                        int adjNodeNo = newRow * n + newCol;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        int ans = 0;
        
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;

                set<int> components;
                
                for (int ind = 0; ind < 4; ind++) {                    
                    int newRow = row + delRow[ind];
                    int newCol = col + delCol[ind];
                    
                    
                    if (newRow>=0 && newRow<n && newCol>=0 && newCol<
                    n && 
                        grid[newRow][newCol] == 1) {
                        
                        /* Perform union and store 
                        ultimate parent in the set */
                        int nodeNumber = newRow * n + newCol;
                        components.insert(ds.findUPar(nodeNumber));
                    }
                }
                
                int sizeTotal = 0;
                
                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }
                
                ans = max(ans, sizeTotal + 1);
            }
        }
       
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
           ans = max(ans, ds.size[ds.findUPar(cellNo)]);
        }
        
        return ans;
    }
};