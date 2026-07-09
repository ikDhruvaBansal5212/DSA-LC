class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int m=grid.size();
        int n=grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        int row[]={1,0,-1,0};
        int col[]={0,1,0,-1};

        int time=0;
        while(!q.empty()){
            int s=q.size();
            bool rotten=false;
            for(int i=0;i<s;i++){
                int sr=q.front().first;
                int sc=q.front().second;
                q.pop();

                for(int p=0;p<4;p++){
                    int nrow=sr+row[p];
                    int ncol=sc+col[p];

                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                        rotten=true;
                        grid[nrow][ncol]=2;
                        q.push({nrow,ncol});
                    }
                }
            }
            if(rotten) time++;
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};