class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int a=n*n;                       //oddSum
        int b=n*(n+1);               //EvenSum

        while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
    }
};