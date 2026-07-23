class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<unsigned long long>> dp(n,vector<unsigned long long>(m,-1));
        return solve(n-1,m-1,dp,s,t);
    }

    int solve(int i,int j,vector<vector<unsigned long long>> &dp,string &s, string &t){
        if(j<0) return 1;
        if(i<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]) return dp[i][j]=solve(i-1,j-1,dp,s,t)+solve(i-1,j,dp,s,t);
        else{
            return dp[i][j]=solve(i-1,j,dp,s,t);
        }
    }
};