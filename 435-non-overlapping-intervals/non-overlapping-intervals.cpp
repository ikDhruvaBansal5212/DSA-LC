class Solution {
public:

    static bool comp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int n=intervals.size();
        int res=0;
        int endtime=intervals[0][1];
        for(int i=1;i<n;i++){
            if(endtime<=intervals[i][0]){
                endtime=intervals[i][1];
            }else{
                res++;
            }
        }
        return res;
    }
};