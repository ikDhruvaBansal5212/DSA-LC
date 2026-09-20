class Solution {
public:
    int reverseDegree(string s) {
        int res=0;
        for(int i=0;i<s.size();i++){
            int val = 26 - (s[i] - 'a');
            res=res+((i+1)*val);
        }
        return res;
    }
};