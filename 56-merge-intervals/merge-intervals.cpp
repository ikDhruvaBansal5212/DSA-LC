class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==0){return intervals;}
        sort(intervals.begin(), intervals.end());
        for(int i=0;i<n;i++){
            int p=intervals[i][0];
            int q=intervals[i][1];
            for(int j=i+1;j<n;j++){
                if(intervals[j][0]<=intervals[i][1]){
                    q=max(intervals[i][1],intervals[j][1]);
                    intervals[i][1]=q;
                    intervals.erase(intervals.begin()+j);
                    n--;
                    j--;
                }
            }
        }
        return intervals;
    }
};