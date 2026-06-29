class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5=0;
        int count10=0;
        int count20=0;

        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                count5++;
            }
            else if(bills[i]==10){
                count5--;
                count10++;
            }
            else{
                count5--;
                if(count10>=1){
                    count10--;
                }
                else{
                    count5-=2;
                }
            }

            if(count5<0 || count10<0 ||count20==-1) return false;
        }
        return true;
    }
};