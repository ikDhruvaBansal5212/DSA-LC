class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int>dis(2,0);

        for(int i=0;i<moves.size();i++){
            if(moves[i]=='U'){
                dis[0]++;
            }
            if(moves[i]=='D'){
                dis[0]--;
            }
            if(moves[i]=='L'){
                dis[1]++;
            }
            if(moves[i]=='R'){
                dis[1]--;
            }
        }
        if(dis[0]==0 && dis[1]==0){return true;}
        else{return false;}
    }
};