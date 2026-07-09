class Solution {
public:
    vector<vector<int>>res;

    void solve(vector<vector<int>>& image, int sr, int sc, int color,int m, int n){
        res[sr][sc]=color;
        int start_color=image[sr][sc];

        int row[]={1,0,-1,0};
        int col[]={0,1,0,-1};
        
        for(int p=0;p<4;p++){
            int nrow=sr+row[p];
            int ncol=sc+col[p];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol]==start_color && res[nrow][ncol]!=color){
                solve(image,nrow,ncol,color,m,n);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        res=image;
        int m=image.size();
        int n=image[0].size();
        solve(image,sr,sc,color,m,n);
        return res;
    }
};