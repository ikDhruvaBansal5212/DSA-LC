class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& arr,int i,int j){
        if(i>j) return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

        return dp[i][j]=max(
            arr[i]-solve(arr,i+1,j),
            arr[j]-solve(arr,i,j-1)
        );
    }

    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        dp.assign(n,vector<int>(n,-1));

        return solve(piles,0,n-1)>0;
    }
};