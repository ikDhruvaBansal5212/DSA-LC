class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L=0,R=0,D=0;
        int n=moves.size();
        for(int i=0;i<n;i++){
            if(moves[i]=='R'){
                R++;
            }
            else if(moves[i]=='L'){
                L++;
            }
            else{
                D++;
            }
        }
        return abs(R-L)+D;
    }
};