class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if ((long long)m * k > n) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int res=-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            int cnt=0;
            int bouque=m;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid){
                    cnt++;
                }
                else{
                    cnt=0;
                }

                if(cnt==k){
                    bouque--;
                    cnt=0;
                }
            }

            if(bouque>0){
                low=mid+1;
            }
            else{
                res=mid;
                high=mid-1;
            }
        }
        return res;

    }
};