class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        queue<pair<int, int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int k=0;k<n;k++){
                matrix[i][k]=0;
            }
            for(int k=0;k<m;k++){
                matrix[k][j]=0;
            }
        }

    }
};