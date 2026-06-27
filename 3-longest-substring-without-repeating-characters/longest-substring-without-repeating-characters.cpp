class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        unordered_map<char,int>mpp;
        int n=s.size();
        if(n==0) return 0;
        int res=INT_MIN;
        while(j<n){
            if(mpp.find(s[j])!=mpp.end() && mpp[s[j]] >= i){
                i=mpp[s[j]] + 1;

            }
           mpp[s[j]]=j;
           res=max(res,j-i+1);
           j++;
        }
        return res;
    }
};