class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        if(k>n){
            return false;
        }

        int total=1;
        for(int i=0;i<k;i++){
            total*=2;
        }
        if (n-k+1 < total)
        return false;

        unordered_set<string> st;
        for(int i=0;i<=n-k;i++){
            string sub=s.substr(i,k);
            st.insert(sub);
        }

        if(st.size()==total){
            return true;
        }

        return false;
    }
};