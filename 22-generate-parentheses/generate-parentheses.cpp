class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string curr="";
        solve(curr,0,0,n);
        return res;
    }

    void solve(string curr,int open,int close,int n){
        if(curr.length()==2*n){
            res.push_back(curr);
            return;
        }

        if(open<n) solve(curr+'(',open+1,close,n);
        if(close<open) solve(curr+')',open,close+1,n);
    }
};