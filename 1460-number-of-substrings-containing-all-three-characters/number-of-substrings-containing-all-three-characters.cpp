class Solution {
public:
    int numberOfSubstrings(string s) {
        int Lastseen[3]={-1,-1,-1};
        int res=0;
        for(int i=0;i<s.size();i++){
            Lastseen[s[i]-'a']=i;
            if(Lastseen[0]!=-1 && Lastseen[1]!=-1 && Lastseen[2]!=-1){
                res+=1+min(Lastseen[0],min(Lastseen[1],Lastseen[2]));
            }
        }
        return res;
    }
};