class Solution {
public:
    int numSteps(string s) {
        int n=s.size();
        int res=0;
        int carry=0;
        for(int i=n-1;i>0;i--){
            int bit=(s[i]-'0')+carry;

            if(bit==0 || bit==2){
                res++;
            }
            else{
                carry=1;
                res=res+2;
            }
        }
        return res+carry;
    }
};