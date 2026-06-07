class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(), nums.end(), 0);

        while(low<=high){
            int mid=(low+high)/2;
            if(count(nums,k,mid)<=k){
                high=mid-1;
            }            
            else{
                low=mid+1;
            }
        }
        return low;
    }

    int count(vector<int>& nums, int k,int mid){
        int cnt=0;
        int partition=1;
        for(int i=0;i<nums.size();i++){
            if(cnt+nums[i]>mid){
                partition++;
                cnt=nums[i];
            }
            else{
                cnt+=nums[i];
            }
        }
        return partition;
    }
};