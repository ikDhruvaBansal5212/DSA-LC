class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cn1=0,cn2=0;
        int el1=INT_MIN,el2=INT_MIN;

        for(int i=0;i<n;i++){
            if(cn1==0 && nums[i]!=el2){
                cn1=1;
                el1=nums[i];
            }
            else if(cn2==0 && nums[i]!=el1){
                cn2=1;
                el2=nums[i];
            }
            else if(el1==nums[i]) cn1++;
            else if(el2==nums[i]) cn2++;

            else{
                cn1--;
                cn2--;
            }
        }

        cn1 = 0;
        cn2 = 0;

        for (int num : nums) {
            if (num == el1) cn1++;
            else if (num == el2) cn2++;
        }
        vector<int> res;
        if (cn1 > n / 3) res.push_back(el1);
        if (cn2 > n / 3) res.push_back(el2);

        return res;
    }
};