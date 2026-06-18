class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int rem=target;
        vector<int> count;
         sort(candidates.begin(), candidates.end());
        solve(0,rem,res,count,candidates);
        return res;
    }

    void solve(int start,int rem,vector<vector<int>> &res,vector<int> &count,vector<int>& candidates){
        if(rem==0){
            res.push_back(count);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i]>rem){
                break;
            }
            count.push_back(candidates[i]);
                solve(i,rem-candidates[i],res,count,candidates);
                count.pop_back();
        }
    }
};