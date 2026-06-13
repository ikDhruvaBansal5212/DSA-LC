class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        if(s.empty()){return "";}

        sort(s.begin(),s.end());
        string first=s[0];
        string last=s[s.size()-1];

        string ans = "";
        int minLength = min(first.size(), last.size());
        for(int i=0;i<minLength;i++){
            if (first[i] != last[i]) break;
            ans += first[i];
        }
        return ans;
    }
};