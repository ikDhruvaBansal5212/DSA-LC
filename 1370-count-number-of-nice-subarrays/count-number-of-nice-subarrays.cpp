class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int l = 0, res = 0, odd = 0;

        for (int r = 0; r < nums.size(); r++) {

            if (nums[r] % 2)
                odd++;

            while (odd > k) {
                if (nums[l] % 2)
                    odd--;
                l++;
            }

            res += r - l + 1;
        }

        return res;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};