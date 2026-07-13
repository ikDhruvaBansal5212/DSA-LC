class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>mat(n,vector<int>(n,1e9));

        for (int i = 0; i < n; i++)
            mat[i][i] = 0;

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];

            mat[u][v]=wt;
            mat[v][u]=wt;
        }

        for (int k = 0; k<n; k++) {
			for (int i = 0; i<n; i++) {
				for (int j = 0; j<n; j++) {
				    if (mat[i][k] == 1e9 || mat[k][j] == 1e9)
                        continue; 
					mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
				}
			}
		}
        int mincount=INT_MAX;
        int res=INT_MAX;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=mincount){
                mincount=count;
                res=i;
            }
        }
        return res;
    }
};