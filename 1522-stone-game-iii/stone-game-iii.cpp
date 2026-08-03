class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& arr,int i){

        if(i>=arr.size())
            return 0;

        if(dp[i]!=INT_MIN)
            return dp[i];

        int ans=INT_MIN;
        int sum=0;

        for(int k=0;k<3 && i+k<arr.size();k++){

            sum+=arr[i+k];

            ans=max(ans,sum-solve(arr,i+k+1));
        }

        return dp[i]=ans;
    }

    string stoneGameIII(vector<int>& arr) {

        dp.assign(arr.size(),INT_MIN);

        int diff=solve(arr,0);

        if(diff>0)
            return "Alice";

        if(diff<0)
            return "Bob";

        return "Tie";
    }
};