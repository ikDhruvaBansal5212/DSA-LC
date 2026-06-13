class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int count=0;
        int res=INT_MIN;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                count++;
                res=max(res,count);
            }
            else if(s[i]==')'){
                count--;
            }
        }
        return max(res,0);
    }
};