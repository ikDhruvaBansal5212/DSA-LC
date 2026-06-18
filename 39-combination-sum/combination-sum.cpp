class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>temp;
        solve(nums,target,0,temp,0);
        return res;
    }

    void solve(vector<int>& nums, int target,int sum,vector<int>temp,int i){
        if(sum==target){
            res.push_back(temp);
            return;
        }
        
        if(i>=nums.size() || sum>target){
            return;
        }

        solve(nums,target,sum,temp,i+1);
        temp.push_back(nums[i]);
        solve(nums,target,sum+nums[i],temp,i);
        return;
    }
};