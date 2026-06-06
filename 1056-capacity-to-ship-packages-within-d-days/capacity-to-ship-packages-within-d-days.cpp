class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int high=0;
        for(int i=0;i<n;i++){
            high+=weights[i];
        }
        int low = *max_element(weights.begin(), weights.end());
        int res=high;

        while(low<=high){
            int mid=low+(high-low)/2;
            int cnt=0;
            int dayst=1;
            for(int i=0;i<n;i++){
                if(cnt+weights[i]>mid){
                    dayst++;
                    cnt=weights[i];
                }
                else{
                    cnt=cnt+weights[i];
                }
                
            }

            if(dayst>days){
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