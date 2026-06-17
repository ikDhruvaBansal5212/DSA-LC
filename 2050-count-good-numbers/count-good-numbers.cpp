class Solution {
public:
    const long long MOD = 1e9 + 7;
    int countGoodNumbers(long long n) {
        long long evens=fn(5,(n+1)/2);
        long long odds=fn(4,n/2);

        return (evens*odds)%MOD;
    }

    long long fn(int x,long long n){
        if(x==1) return 1;
        if(n==0) return 1;
        if(n==1) return x;

        if(n%2==0){
            long long half= fn(x,n/2);
            return (half*half)%MOD;
        }

        return x*fn(x,n-1)%MOD;
    }
};