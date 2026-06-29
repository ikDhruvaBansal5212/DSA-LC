class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        if(s.size()<t.size()) return res;

        if(s.size()==t.size() && s==t) return s;
        int n=s.size();
        unordered_map<char,int>mp;

        for(char ch:t){
            mp[ch]++;
        }
        int req_count=t.size();
        int i=0,j=0;
        int windowsize=INT_MAX;
        int start_i=0;

        while(j<n){
            char ch=s[j];

            if(mp[ch]>0){
                req_count--;
            }
            mp[ch]--;

            while(req_count==0){
                int curr_wind_size=j-i+1;
                if(curr_wind_size<windowsize){
                    windowsize=curr_wind_size;
                    start_i=i;
                }
                mp[s[i]]++;      

                if(mp[s[i]]>0){
                    req_count++;
                }
                i++;          
            }
            j++;
        }
    if(windowsize==INT_MAX){
        return "";
    }
    else return s.substr(start_i,windowsize);
    }
};