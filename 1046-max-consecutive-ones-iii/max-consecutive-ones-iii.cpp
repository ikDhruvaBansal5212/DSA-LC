class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int i = 0;
        int count = 0;
        int k1 = k;
        int start = 0; 

        while (i < n) {
            if (nums[i] == 1) {
                count++;
            } else if (nums[i] == 0) {
                if (k > 0) {
                    count++;
                    k--;
                } else {
                    while (nums[start] != 0) {
                        start++;
                        count--;
                    }
                    start++;  
                }
            }

            res = max(res, count);
            i++;
        }

        return res;
    }
};
