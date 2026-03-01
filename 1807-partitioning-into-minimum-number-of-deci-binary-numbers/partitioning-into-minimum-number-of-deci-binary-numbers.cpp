class Solution {
public:
    int minPartitions(string n) {
        int res=INT_MIN;
        for(int i=0;i<n.size();i++){
            int digit=n[i]-'0';
            if(digit==9){
                return 9;
            }
            else{
                 if(digit>res){
                    res=digit;
                 }
            }
        }        
        return res;
    }
};