class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;   //{diff,{i,j}};

        vector<vector<int>>diff(m,vector<int>(n,INT_MAX));
        diff[0][0]=0;
        q.push({0,{0,0}});

        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};

        while(!q.empty()){
            int d=q.top().first;
            int i=q.top().second.first;
            int j=q.top().second.second;
            q.pop();

            for(int k=0;k<4;k++){
                int nr=i+row[k];
                int nc=j+col[k];

                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    int neweffort=max(abs(heights[i][j]-heights[nr][nc]),d);
                    if(neweffort<diff[nr][nc]){
                        diff[nr][nc]=neweffort;
                        q.push({neweffort,{nr,nc}});
                    }
                }
            }
        }

        return diff[m-1][n-1];
    }
};