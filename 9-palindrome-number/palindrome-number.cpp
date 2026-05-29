class Solution {
public:
    bool isPalindrome(int x) {
        int t=x;
        if(x<0){
            return false;
        }
        long long y=0;
        while(x!=0){
            int dig=x%10;
            x=x/10;
            y=y*10+dig;
        }
        x=t;
        while(x!=0 && y!=0){
            if(x%10==y%10){
                x/=10;
                y/=10;
            }
            else{
                return false;
            }
        }
        return true;
    }
};