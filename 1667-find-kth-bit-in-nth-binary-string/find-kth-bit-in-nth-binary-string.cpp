class Solution {
public:
    char findKthBit(int n, int k) {
        string s="0";
        if(n==1){
            return '0';
        }
        for(int i=2;i<=n;i++){
            int prevSize=s.size()-1;
            s.push_back('1');
            while(prevSize>=0){
                if(s[prevSize]=='0'){
                    s.push_back('1');
                }
                else{
                    s.push_back('0');
                }
                prevSize--;
            }
        }

        return s[k-1];
    }
};