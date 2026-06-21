class Solution {
public:
    int divide(int dividend, int divisor) {
        long n=dividend;
        long d=divisor;

        if(d==n) return 1;

        bool sign=true;
        if(d>=0 && n<0) sign=false;
        else if(d<=0 && n>0) sign=false;
        
        d=abs(d);
        n=abs(n);
        long quotient=0;

        while(n>=d){
            int cnt=0;
            while(n>= (d<<(cnt+1))){
                cnt+=1;
            }
            quotient+=1<<cnt;
            n-=(d<<cnt);
        }

        if(quotient==(1<<31) && sign){
            return INT_MAX;
        }
        if(quotient==(1<<31) && !sign){
            return INT_MIN;
        }

        return sign?quotient : -quotient;
    }
};