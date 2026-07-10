class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>res(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }

        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};

        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int dist=q.front().second;
            q.pop();

            res[i][j]=dist;

            for(int k=0;k<4;k++){
                int nrow=i+row[k];
                int ncol=j+col[k];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]!=1){
                    q.push({{nrow,ncol},dist+1});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return res;
    }
};
















