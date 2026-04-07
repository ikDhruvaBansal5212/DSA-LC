class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int l=0;
        int h=m-1;
        int mid=0;
        while(l<=h){
            mid=(l+h)/2;
            int maxele=0;

            int row;
            for(int i=0;i<n;i++){
                if(mat[mid][i]>maxele){
                    maxele=mat[mid][i];
                    row=i;
                }
            }

            int left = mid - 1 >= 0 ? mat[mid-1][row] : INT_MIN;
            int right = mid + 1 < m ? mat[mid+1][row] : INT_MIN;

           if (mat[mid][row] > left && mat[mid][row] > right) {
                  return {mid, row};
              } 
              else if (left > mat[mid][row]) {
                  h = mid - 1;
              } 
              else {
                  l = mid + 1;
              }
        }
        return {-1,-1};
    }
};