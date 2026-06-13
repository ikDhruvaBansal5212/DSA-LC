class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        s=s+s;
        
        int n=goal.size();

        for(int i=0;i<=s.size()-n;i++){
            if(s.substr(i,n)==goal){
                return true;
            }
        }
        return false;
    }
};