class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int max=*max_element(piles.begin(), piles.end());
        int high=max;
        int res=INT_MAX;
        if(n==h){
            return max;
        }
        long long cnt=0;
        while(low<=high){
            int mid=low+(high-low)/2;

            cnt=0;
            for(int i=0;i<n;i++){
                int t=piles[i]/mid;
                if(t==0){
                    cnt++;
                }
                else if(t*mid<piles[i]){
                    cnt=cnt+t+1;
                }
                else{
                    cnt=cnt+t;
                }
            }

            if(cnt<=h){
                high=mid-1;
                res=min(res,mid);
            }
            else{
                low=mid+1;
            }
        }
        return res; 
    }
};