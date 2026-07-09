class Solution {
public:

    void solve(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& vis,int m,int n){
        vis[i][j]=1;

        int row[]={1,0,-1,0};
        int col[]={0,1,0,-1};
        
        for(int p=0;p<4;p++){
            int nrow=i+row[p];
            int ncol=j+col[p];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==0 && grid[nrow][ncol]=='1'){
                solve(nrow,ncol,grid,vis,m,n);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && vis[i][j]!=1){
                    res++;
                    solve(i,j,grid,vis,m,n);
                }
            }
        }
        return res;
    }
};