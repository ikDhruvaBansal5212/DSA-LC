class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int m=queries.size();
        int n=dictionary.size();
        vector<string> res;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int p=queries[i].size();
                int q=dictionary[j].size();
                int count=0;
                int k=0;
                if(p==q){
                    while(k<p){
                        if(queries[i][k]!=dictionary[j][k]){
                            count++;
                        }
                        k++;
                    }
                }
                if(count<=2){
                    res.push_back(queries[i]);
                    break;
                }
            }
        }
        return res;
    }
};