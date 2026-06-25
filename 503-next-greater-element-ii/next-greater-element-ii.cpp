class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>res(n);
        for(int i=2*n-1;i>=0;i--){
            int ind=i%n;
            while(!st.empty() && st.top()<=nums[ind]){
                st.pop();
            }

            if(i<n){
                if(st.empty()){
                    res[i]=-1;
                }
                else{
                    res[i]=st.top();
                }
            }
            st.push(nums[ind]);
        }
        return res;
    }
};