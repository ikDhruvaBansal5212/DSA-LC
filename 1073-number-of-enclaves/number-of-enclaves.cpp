class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));  
        queue<pair<int, int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(grid[i][j]==1){
                        vis[i][j]=1;
                        q.push({i,j});
                    }
                }
            }
        }

        int row[]={-1,0,+1,0};
        int col[]={0,-1,0,+1};

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int nrow=i+row[k];
                int ncol=j+col[k];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n 
                    && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
            }
        }

            int res=0;

            for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    res++;
                }
                }
            }
        
        return res;
        }
};