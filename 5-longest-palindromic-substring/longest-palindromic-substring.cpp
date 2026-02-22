class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1)); //0 means false and 1 means true  
        int maxy=0;
        int ind=-1;
        for(int L=1;L<=n;L++){
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;
                if(i==j){
                    dp[i][j]=1;
                    if(maxy<j-i+1){
                        maxy=j-i+1;
                        ind=i;
                    }

                }
                else if(i+1==j && s[i]==s[j]){
                    dp[i][j]=1;
                    if(maxy<j-i+1){
                        maxy=j-i+1;
                        ind=i;
                    }
                }
                else{
                    dp[i][j]=(dp[i+1][j-1] && s[i]==s[j]);
                    if(dp[i][j]==1){
                        if(maxy<j-i+1){
                        maxy=j-i+1;
                        ind=i;
                    }
                    }
                }
            }
        }
        return s.substr(ind,maxy);
    }
};