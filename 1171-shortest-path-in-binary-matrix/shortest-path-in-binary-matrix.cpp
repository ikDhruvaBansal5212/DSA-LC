class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
        return -1;
        queue<pair<int,pair<int,int>>>q;  //{dis,{i,j}};
        q.push({1,{0,0}});
        

        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        dis[0][0]=1;
        
        while(!q.empty()){
            int i=q.front().second.first;
            int j=q.front().second.second;
            int dist=q.front().first;
            q.pop();

            int row[] = {-1,-1,-1,0,0,1,1,1};
            int col[] = {-1,0,1,-1,1,-1,0,1};

            for(int k=0;k<8;k++){
                int nr=i+row[k];
                int nc=j+col[k];

                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0){
                    if(dist+1 < dis[nr][nc]){
                        q.push({dist+1,{nr,nc}});
                        dis[nr][nc]=dist+1;
                    }
                }
            }
        }
        if(dis[n-1][n-1]!=INT_MAX) return dis[n-1][n-1];
        return -1;
    }
};